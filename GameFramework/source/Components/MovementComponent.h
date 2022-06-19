#pragma once

#include "..\Components\Component.h"
#include "..\Components\RectTransform.h"
#include "..\Components\Controller.h"

/**
 * \brief Component to move object with a RectTransform component inside the world scene
 */
class MovementComponent : public Component
{
public:
	float speed;

	Controller* inputController;
	RectTranform* transform;

public:
	MovementComponent();
	~MovementComponent() override;

	[[nodiscard]] sf::Vector2f GetVelocity() const;
	void SetVelocity(float speed) { this->speed = speed; }
	[[nodiscard]] sf::Vector2f GetMotionVector() const;

	[[nodiscard]] bool IsMotionValid() const 
	{ return (inputController->forwardMovement || inputController->rightwardMovement); }

	void On_Update(const float delta_time) override;
};