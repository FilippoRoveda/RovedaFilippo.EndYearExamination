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


	/**
	* \brief Set texture from a path given by user, if this is not valid return a Debug warning.
	* Otherwise set this whit the given value of smoothness and repeat.
	* \return axis vector
	*/
	void SetTexturePath(std::string texture_path, bool smooth, bool repeat);
};