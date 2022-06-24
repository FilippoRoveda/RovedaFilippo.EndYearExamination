#include "..\Components\MovementComponent.h"
#include <iostream>

MovementComponent::MovementComponent() : Component ("Movement Component")
{
	speed = 1000;
	jumpForce = 0;
}

MovementComponent::~MovementComponent()
{
	delete inputController;
	delete transform;
}

sf::Vector2f MovementComponent::GetVelocity() 
{
	direction = inputController->Get_Axis_Vector();
	sf::Vector2f velocity = { direction.x * speed, direction.y * speed };
	return velocity;
}

sf::Vector2f MovementComponent::GetMotionVector() 
{
	velocity = GetVelocity();
	const float length = sqrt(velocity.x * velocity.x + velocity.y * velocity.y);

	if (length == 0.0f) return { 0,0 };

	return { velocity.x / length, velocity.y / length };
}

void MovementComponent::On_Update(const float delta_time)
{
	if (!IsMotionValid()) return;

	auto nextPos = sf::Vector2f{ 0,0 };
	if (isJumping)
	{
		 nextPos = transform->GetTransform()->getPosition() + sf::Vector2f(GetMotionVector().x * 300 * delta_time, 
							  GetMotionVector().y * speed * delta_time - jumpForce * delta_time);
	}

	else {
		 nextPos = transform->GetTransform()->getPosition() + sf::Vector2f(GetMotionVector().x * 600 * delta_time, 
						      GetMotionVector().y * speed * delta_time - jumpForce * delta_time);
	}
	//printf("new pos: %f, %f\n", nextPos.x, nextPos.y);
	nextPos.y += 14,6 * delta_time * delta_time;
	transform->SetPosition(nextPos.x, nextPos.y);
	jumpForce -= 14, 6 * delta_time * delta_time;
	if(jumpForce<=0.0f)
	{
		jumpForce = 0.0f;
	}

}

void MovementComponent::Jump()
{
	if (collider == nullptr) { return; }
	//std::cout << "COLL DIR IN MOV:" << collider->collisionDirection.x << "     " << collider->collisionDirection.y << std::endl;
		if ( collider->collisionDirection->y == 1 && isJumping == false)
		{
			printf("								Jumping\n\n\n");
			jumpForce = 1300;
			isJumping = true;
			collider->collisionDirection->y = 0;
		}
		else if(collider->collisionDirection->y == 1) { isJumping = false; }
}
