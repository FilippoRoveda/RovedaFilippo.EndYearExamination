#pragma once
#include "Component.h"
#include "RectTransform.h"

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

	bool CheckCollision(Collider* other, float push);
	sf::Vector2f GetPosition() { return body->GetTransform()->getPosition(); }
	sf::Vector2f GetHalfSize() { return body->GetTransform()->getSize() / 2.0f; }

	//Forse devo modificare la velocità dell'altro
	void Move(float x, float y) { body->GetTransform()->move(x, y); }

	sf::Vector2f* GetCollisionDirection() { return collisionDirection; }

};