#include "..\Components\RectTransform.h"

RectTranform::RectTranform() : Component("Rect Transform") 
{
	Disable();	// Disables update and fixed update callbacks

	position = sf::Vector2f(960, 540);
	rotation = 0;
	scale = sf::Vector2f(1, 1);

	transform = new sf::RectangleShape(scale);
}

RectTranform::RectTranform(sf::Vector2f position, float rotation, sf::Vector2f scale) : Component("Rect Transform")
{
	Disable();

	this->position = position;
	this->rotation = rotation;
	this->scale = scale;

	transform = new sf::RectangleShape(scale);
}

RectTranform::~RectTranform()
{
	delete transform;
}

void RectTranform::SetPosition(float x, float y) const
{
	transform->setPosition(x, y);
}

void RectTranform::SetRotation(float angle) const
{
	transform->setRotation(angle);
}

void RectTranform::SetScale(float x, float y) const
{
	transform->setScale(x, y);
}

sf::RectangleShape* RectTranform::GetTransform() const
{
	return transform;
}
