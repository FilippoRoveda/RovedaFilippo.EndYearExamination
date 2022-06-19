#pragma once
#include "Area2D.h"
#include "..\Components\Renderer2D.h"

	class Sprite : public Area2D
	{
	public:
		Sprite();
		~Sprite() override;

		Renderer2D* renderer;
	};