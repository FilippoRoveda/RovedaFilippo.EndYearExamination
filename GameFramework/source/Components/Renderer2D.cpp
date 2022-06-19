#include "Renderer2D.h"
#include "..\Classes\GameObject.h"
#include "..\Classes\Area2D.h"

Renderer2D::Renderer2D() : Component("Renderer 2D")
{
	_texture = nullptr;
}

Renderer2D::Renderer2D(std::string texture_path, bool smooth, bool repepat) : Component("Renderer 2D")
{
	_texture = new sf::Texture();
	_texture->create(20, 20);
	if (!_texture->loadFromFile(texture_path))
	{
		printf("Can't load texture at path [%s]\n", texture_path.c_str());
		return;
	}

	_texture->setSmooth(smooth);
	_texture->setRepeated(repepat);

	const auto rect = Get_Owner()->Get_Component<RectTranform, RectTranform>();

	if (!rect)
	{
		printf("Can't load RectTranform component from owner.\n");
		return;
	}

	rect->GetTransform()->setTexture(_texture);
}

Renderer2D::~Renderer2D()
{
	delete _texture;
}

void Renderer2D::SetTexturePath(std::string texture_path, bool smooth, bool repeat)
{
	delete _texture;
	_texture = new sf::Texture();
	if (!_texture->loadFromFile(texture_path))
	{
		printf("Can't load texture at path[%s]\n", texture_path.c_str());
		return;
	}
	_texture->setSmooth(smooth);
	_texture->setRepeated(repeat);

	const auto owner = dynamic_cast<Area2D*>(this->Get_Owner());
	if (!owner)
	{
		printf("Owner casting failed!\n");
		return;
	}

	owner->rectTransform->GetTransform()->setTexture(_texture);

}
