#include "Collider.h"
#include <iostream>

Collider::Collider(RectTranform* body, float push) : Component("Collider component")
{
	this->body = body;
	this->push = push;
	collisionDirection = new sf::Vector2f{ 0,0 };
}

Collider::~Collider()
{
	delete collisionDirection;
}

bool Collider::CheckCollision(Collider* other, float push)
{

	sf::Vector2f otherPos = other->GetPosition();
	sf::Vector2f otherHalfSize = other->GetHalfSize();

	sf::Vector2f myPos = GetPosition();
	sf::Vector2f myHalfSize = GetHalfSize();

	sf::Vector2f deltaDistance = otherPos - myPos;
	sf::Vector2f intersect = { abs(deltaDistance.x) - (otherHalfSize.x + myHalfSize.x), abs(deltaDistance.y) - (otherHalfSize.y + myHalfSize.y) };
	
	if (intersect.x < 0.0f && intersect.y < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);
		if (intersect.x > intersect.y)
		{
			if (deltaDistance.x > 0.0f)
			{
				Move(intersect.x * (1.0f - push), 0.0f);
				if (other->isMovable == true)
				{
					other->Move(-intersect.x * push, 0.0f);
				}

				other->collisionDirection->x = 1.0f;
				other->collisionDirection->y = 0.0f;
				//printf("						Collision SX\n");
				
			}
			else
			{
				Move(-intersect.x * (1.0f - push), 0.0f);
				if (other->isMovable == true)
				{
					if (other->isMovable) other->Move(intersect.x * push, 0.0f);
				}

				other->collisionDirection->x = -1.0f;
				other->collisionDirection->y = 0.0f;
				//printf("						Collision DX\n");
				
			}
			//std::cout << "COLLISION DIR:" << collisionDirection->x << "     " << collisionDirection->y << std::endl;
		}
		else
		{
			if (deltaDistance.y > 0.0f)
			{
				Move(0.0f, intersect.y * (1.0f - push));
				if (other->isMovable == true)
				{
					other->Move(0.0f, -intersect.x * push);
				}
				other->collisionDirection->x = 0.0f;
				other->collisionDirection->y = -1.0f;

				//printf("						Collision SU\n");
				
			}
			else
			{
				Move(0.0f, -intersect.y * (1.0f - push));
				if (other->isMovable == true)
				{
					other->Move(0.0f, intersect.y * push);
				}


				other->collisionDirection->x = 0.0f;
				other->collisionDirection->y = 1.0f;

				//printf("						Collision GIU\n");
				
			}
			//std::cout << "COLLISION DIR:" << collisionDirection->x << "     " << collisionDirection->y << std::endl;
		}
		return true;
	}
	
	return false;
}
