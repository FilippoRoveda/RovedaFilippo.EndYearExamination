#include "Collider.h"

Collider::Collider(RectTranform* body, float push) : Component("Collider component")
{
	this->body = body;
	this->push = push;
}

Collider::~Collider()
{
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
		printf("						Collision detecteed\n");
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersect.x > intersect.y)
		{
			if (deltaDistance.x > 0.0f)
			{
				Move(intersect.x * (1.0f - push), 0.0f);
				other->Move(-intersect.x * push, 0.0f);
			}
			else
			{
				Move(-intersect.x * (1.0f - push), 0.0f);
				other->Move(intersect.x * push, 0.0f);
			}
		}
		else
		{
			if (deltaDistance.y > 0.0f)
			{
				Move(0.0f, intersect.y * (1.0f - push));
				other->Move(0.0f, -intersect.x * push);
			}
			else
			{
				Move(0.0f, -intersect.y * (1.0f - push));
				other->Move(0.0f, intersect.y * push);
			}
		}
		return true;
	}
	
	return false;
}
