#pragma once
#include "GameObject.h"
#include "..\Components\RectTransform.h"

class Area2D : public GameObject
{
public:
	Area2D();
	Area2D(std::string name, float scale, sf::Color color);
	~Area2D() override;

	RectTranform* rectTransform;

};