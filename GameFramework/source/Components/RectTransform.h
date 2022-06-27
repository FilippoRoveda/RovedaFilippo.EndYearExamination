#pragma once

#include "..\Components\Component.h"
#include "..\include\SFML\Graphics.hpp"
/**
 * \brief Component that allows to represent portion of space in viewport.
 */

class RectTranform : public Component
{
	friend class Application;

private:
	sf::Vector2f position;
	float rotation;
	sf::Vector2f scale;

	sf::RectangleShape* transform;

public:
	RectTranform();
	explicit RectTranform(sf::Vector2f position, float rotation, sf::Vector2f scale);

	~RectTranform() override;


	/**
 * \brief Set area position in world space.
 * \param x : horizontal position.
 * \param y : vertical position.
 */
	void SetPosition(float x, float y) const;

	/**
 * \brief Set area rotation in world space.
 * \param angle : the rotation angle in degrees.
 */
	void SetRotation(float angle) const;


	/**
 * \brief Set size in pixel for this area in world space.
 * \param x : number of pixel on X.
 * \param y : number of pixel on Y.
 */
	void SetScale(float x, float y) const;

	/**
 * \brief Get the transform data.
 * \return Area transform.
 */
	[[nodiscard]] sf::RectangleShape* GetTransform()const;


	/**
* \brief Get the position data.
* \return current position.
*/
	sf::Vector2f GetPosition() { return position; }
};