#include "Area2D.h"

Area2D::Area2D() : GameObject("Area 2D")
{
	rectTransform = new RectTranform();
	rectTransform->SetScale(32, 32);
	rectTransform->GetTransform()->setFillColor(sf::Color::White);

	Add_Component(rectTransform);
}

Area2D::Area2D(std::string name, float scale, sf::Color color)
{
	this->name = name;
	rectTransform = new RectTranform();
	rectTransform->SetScale(scale, scale);
	rectTransform->GetTransform()->setFillColor(color);

	Add_Component(rectTransform);
}

Area2D::~Area2D()
{
	delete rectTransform;
}