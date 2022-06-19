#include "..\Components\MovementComponent.h"

MovementComponent::MovementComponent() : Component ("Movement Component")
{
	speed = 10;
}

MovementComponent::~MovementComponent()
{
	delete inputController;
	delete transform;
}

sf::Vector2f MovementComponent::GetVelocity() const
{
	auto direction = inputController->Get_Axis_Vector();
	sf::Vector2f velocity = { direction.x * speed, direction.y * speed };
	return velocity;
}

sf::Vector2f MovementComponent::GetMotionVector() const
{
	const auto velocity = GetVelocity();
	const float length = sqrt(velocity.x * velocity.x + velocity.y * velocity.y);

	if (length == 0.0f) return { 0,0 };

	return { velocity.x / length, velocity.y / length };
}

void MovementComponent::On_Update(const float delta_time)
{
	if (!IsMotionValid()) return;

	auto nextPos = transform->GetTransform()->getPosition() + sf::Vector2f(GetMotionVector().x * speed * delta_time, GetMotionVector().y * speed * delta_time);
	printf("new pos: %f, %f\n", nextPos.x, nextPos.y);
	transform->SetPosition(nextPos.x, nextPos.y);

}
