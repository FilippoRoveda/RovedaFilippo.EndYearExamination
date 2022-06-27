#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(RectTranform* texture, sf::Vector2u imgCount, float switchTime) : Component("Animation component")
{
	animated = texture;
	currentTexture = animated->GetTransform()->getTexture();
	this->imgCount = imgCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImg.x = 0;
	currentImg.y = 0;

	uvRect.width = animated->GetTransform()->getTexture()->getSize().x / float(imgCount.x);
	uvRect.width = animated->GetTransform()->getTexture()->getSize().y / float(imgCount.y);
}

AnimationComponent::~AnimationComponent()
{
}

void AnimationComponent::On_Update(const float delta_time)
{
	if (animated->GetTransform()->getTexture() != currentTexture)
	{
		currentTexture = animated->GetTransform()->getTexture();
		imgCount.x = currentTexture->getSize().x / 168;
		imgCount.y = currentTexture->getSize().y / 356;
		currentImg.x = 0;
		currentImg.y = 0;
	}


	totalTime += delta_time;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImg.x++;

		if (currentImg.x >= imgCount.x)
		{
			currentImg.x = 0;
			currentImg.y++;
			if (currentImg.y >= imgCount.y)
			{
				currentImg.x = 0;
				currentImg.y = 0;
			}
		}

		uvRect.left = currentImg.x; 
		uvRect.top = currentImg.y; 
		animated->GetTransform()->setTextureRect(sf::IntRect(uvRect.left*168, uvRect.top*356, 168,356));
	}
}
