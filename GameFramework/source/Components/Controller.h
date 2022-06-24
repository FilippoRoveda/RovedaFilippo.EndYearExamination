#pragma once
#include "..\Components\Component.h"
//#include "Components/MovementComponent.h"
#include "..\include\SFML\Graphics.hpp"

/**
*  /brief Component that manage device inputs
*/
class MovementComponent;
class Controller : public Component
{
	friend class Application;
	friend class MovementComponent;

private:
	bool forwardMovement;
	bool rightwardMovement;
	float XAxis, YAxis;

	MovementComponent* movementComponent;




protected:
	void On_Update(const float delta_time) override;
	void On_Fixed_Update(const float delta_time) override;

public:
	Controller();
	Controller(MovementComponent* movementComponent );
	~Controller() override;

	void SetMovementComponent(MovementComponent* movementComponent) {
		this->movementComponent = movementComponent;
	}

	/**
 * \brief get all axis component as 2D vector
 * \return axis vector
 */
	[[nodiscard]] sf::Vector2f Get_Axis_Vector() { return { XAxis, YAxis }; }
};

	