#pragma once
#include "GameObject.h"
#include "..\Components\RectTransform.h"

/**
* \brief GameObject that contain by default a RectTranform component.
*/
class Area2D : public GameObject
{
public:
	RectTranform* rectTransform;

public:
	Area2D();
	Area2D(std::string name, float scale, sf::Color color);
	~Area2D() override;



};