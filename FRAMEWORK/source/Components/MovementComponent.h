#pragma once

#include "..\Components\Component.h"
#include "..\Components\RectTransform.h"
#include "..\Components\Controller.h"
#include "..\Components\Collider.h"
#include "..\Components\Renderer2D.h"
#include "dllclasses.h"

/**
 * \brief Component to move object with a RectTransform component inside the world scene
 */

class DECLSPEC MovementComponent : public Component
{
public:
	float speed;
	bool isJumping = false;
	bool wasJumping = false;
	float maxJumpForce = 1550.0f;
	float currentJumpForce = 0.0f;


	//Context pointer links
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
	/// <summary>
	/// Set collider Handled by this compnent.
	/// </summary>
	/// <returns></returns>
	void SetCollider(Collider* collider) { this->collider = collider; }

	/// <summary>
	/// Remove collider Handled by this compnent.
	/// </summary>
	/// <returns></returns>
	void RemoveCollider() { collider = nullptr; }

	/// <summary>
	/// Set renderer Handled by this compnent.
	/// </summary>
	/// <returns></returns>
	void SetRenderer(Renderer2D* rederer) { this->rederer = rederer; }

	/// <summary>
	/// Remove renderer Handled by this compnent.
	/// </summary>
	/// <returns></returns>
	void RemoveRenderer() { rederer = nullptr; }


	/// <summary>
	/// Calculate velocity based on the direction returned by handled controller.
	/// </summary>
	/// <returns>actualVelocity</returns>
	[[nodiscard]] sf::Vector2f GetVelocity();

	/// <summary>
	///	Set speed for that moved GameObject.
	/// </summary>
	/// <returns>speed</returns>
	void SetSpeed(float speed) { this->speed = speed; }

	/// <summary>
	///	Return the motion versor of the actual GameObject velocity.
	/// </summary>
	/// <returns>motion versor</returns>
	[[nodiscard]] sf::Vector2f GetMotionVersor();

	/// <summary>
	///	Return false if no movement input is detected.
	/// </summary>
	/// <returns>true or false</returns>
	[[nodiscard]] bool IsMotionValid() 
	{ return (inputController->forwardMovement || inputController->rightwardMovement); }



	/// <summary>
	///	Update position and animation of the current handled GameObject.
	/// Handle jump force using also a gravity like negative Yaxis accelation.
	/// </summary>
	/// <returns></returns>
	void On_Update(const float delta_time) override;


	/// <summary>
	///	If the player is touching a surface whit his lower side consent a jump action.
	/// </summary>
	/// <returns></returns>
	void Jump();
};