#pragma once

#include "..\Components\Component.h"
#include "SFML/Graphics.hpp"


/**
 * \brief Component that allows to render texture in a area space in viewport.
 */

class Renderer2D : public Component
{
	friend class Application;

protected:
	sf::Texture* _texture;

public:
	Renderer2D();
	explicit Renderer2D(std::string texture_path, bool smooth, bool repeat);
	~Renderer2D() override;

	void SetTexturePath(std::string texture_path, bool smooth, bool repepat);
};