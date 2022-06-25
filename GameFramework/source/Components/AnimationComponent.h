#pragma once
#include "Component.h"
#include "RectTransform.h"

class AnimationComponent : public Component
{
public:
	AnimationComponent(RectTranform* texture, sf::Vector2u imgCount, float switchTime);
	~AnimationComponent();

public:
	sf::IntRect uvRect;

	void On_Update(const float delta_time) override;

private:
	sf::Vector2u imgCount;
	sf::Vector2u currentImg;

	float totalTime;
	float switchTime;

	RectTranform* animated;
};