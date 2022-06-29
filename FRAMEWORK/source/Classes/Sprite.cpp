#include "Sprite.h"

Sprite::Sprite() : Area2D()
{
	renderer = new Renderer2D();
	Add_Component(renderer);
}

Sprite::~Sprite()
{
	delete rectTransform;
	delete renderer;
}
