#pragma once
#include "Area2D.h"
#include "..\Components\Renderer2D.h"

/**
* \brief Area2D object that contain by default a Renderer2D component to show texture in scene.
*/
	class Sprite : public Area2D
	{
	public:
		Sprite();
		~Sprite() override;

		Renderer2D* renderer;
	};