#pragma once
#include "Component.h"
#include "RectTransform.h"



/**
* \brief Collider component that detect and handle collision between another collider component.
* Can be attached to every rect transform.
*/
class Collider : public Component
{
private:
	RectTranform* body;
public:
	float push;
	sf::Vector2f* collisionDirection;

	bool isMovable = true;

public:
	Collider(RectTranform* body, float push);
	~Collider();


	/// <summary>
	/// Detect if two Collider are colliding. This use (AABB) algorythm checking 2 GameObject origin distance,
	/// detect interpolation using their face half size and finally decide the direction of the interpolation
	/// based on the X/Y interpolation vector values.
	/// </summary>
	/// <returns></returns>
	bool CheckCollision(Collider* other, float push);

	/// <summary>
	/// Get current scene position of the handled RectTransform.
	/// </summary>
	/// <returns></returns>
	sf::Vector2f GetPosition() { return body->GetTransform()->getPosition(); }


	/// <summary>
	/// Get the half size of the linked RectTransform for detecting interpolation.
	/// </summary>
	/// <returns></returns>
	sf::Vector2f GetHalfSize() { return body->GetTransform()->getSize() / 2.0f; }


	/// <summary>
	/// Move of an x/y offset the RectTransform linked to this component.
	/// </summary>
	/// <returns></returns>
	void Move(float x, float y) { body->GetTransform()->move(x, y); }


	/// <summary>
	/// Return a vector containing collision direction based on wich part of the collider is colliding.
	/// </summary>
	/// <returns>collision direction (+/- 1(x, +/-(1) y))</returns>
	sf::Vector2f* GetCollisionDirection() { return collisionDirection; }

};