#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(RectTranform* texture, sf::Vector2u imgCount, float switchTime) : Component("Animation component")
{
	animated = texture;
	currentTexture = animated->GetTransform()->getTexture();
	this->imgCount = imgCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImg.x = 0;

	uvRect.width = animated->GetTransform()->getTexture()->getSize().x / float(imgCount.x);
}

AnimationComponent::~AnimationComponent()
{
}

void AnimationComponent::On_Update(const float delta_time)
{
	if (animated->GetTransform()->getTexture() != currentTexture)
	{
		currentTexture = animated->GetTransform()->getTexture();
		imgCount = { currentTexture->getSize().x / 168, currentTexture->getSize().y / 356 };
	}

	currentImg.y = 1;
	totalTime += delta_time;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImg.x++;

		if (currentImg.x >= imgCount.x)
		{
			currentImg.x = 0;
		}
		uvRect.left = currentImg.x; //* uvRect.width;
		//uvRect.top = currentImg.y; //* uvRect.height;
		animated->GetTransform()->setTextureRect(sf::IntRect(uvRect.left*uvRect.width, 0, 168, 356));

		
	}
}
