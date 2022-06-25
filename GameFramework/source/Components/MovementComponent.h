#pragma once

#include "..\Components\Component.h"
#include "..\Components\RectTransform.h"
#include "..\Components\Controller.h"
#include "..\Components\Collider.h"
#include "..\Components\Renderer2D.h"

/**
 * \brief Component to move object with a RectTransform component inside the world scene
 */

class MovementComponent : public Component
{
public:
	float speed;
	bool isJumping = false;
	bool wasJumping = false;
	float maxJumpForce = 1300;
	float currentJumpForce;

	Controller* inputController = nullptr;
	RectTranform* transform = nullptr;
	Collider* collider = nullptr;
	Renderer2D* rederer = nullptr;


protected:
	int orientation = 1;
	sf::Vector2f direction = {0,0};
	sf::Vector2f velocity = {0,0};

public:
	MovementComponent();
	~MovementComponent() override;

	void SetCollider(Collider* collider) { this->collider = collider; }
	void RemoveCollider() { collider = nullptr; }
	void SetRenderer(Renderer2D* rederer) { this->rederer = rederer; }
	void RemoveRenderer() { rederer = nullptr; }

	[[nodiscard]] sf::Vector2f GetVelocity();
	void SetVelocity(float speed) { this->speed = speed; }
	[[nodiscard]] sf::Vector2f GetMotionVector();

	[[nodiscard]] bool IsMotionValid() 
	{ return (inputController->forwardMovement || inputController->rightwardMovement); }

	void On_Update(const float delta_time) override;

	void Jump();
};