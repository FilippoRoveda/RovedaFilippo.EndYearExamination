#pragma once
#include "GameObject.h"
#include "..\Components\RectTransform.h"
#include "dllclasses.h"

/**
* \brief GameObject that contain by default a RectTranform component.
*/
class DECLSPEC Area2D : public GameObject
{
public:
	RectTranform* rectTransform;

public:
	Area2D();
	Area2D(std::string name, float scale, sf::Color color);
	~Area2D() override;



};