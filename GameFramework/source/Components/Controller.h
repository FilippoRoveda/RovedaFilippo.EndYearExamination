#pragma once
#include "..\Components\Component.h"
#include "..\include\SFML\Graphics.hpp"

class MovementComponent;


/**
*  /brief Component that manage device inputs.
*/
class Controller : public Component
{
	friend class Application;
	friend class MovementComponent;

private:
	bool forwardMovement = false;
	bool rightwardMovement = true;
	float XAxis = 0.0f, YAxis = 0.0f;

	MovementComponent* movementComponent = nullptr;


protected:
	void On_Update(const float delta_time) override;
	void On_Fixed_Update(const float delta_time) override;

public:
	/**
	* \Default onstructor.
	* \return void
	*/
	Controller();
	/**
	* \Constructor, set context.
	* \return void
	*/
	Controller(MovementComponent* movementComponent );
	/**
	* \Destructor.
	* \return void
	*/
	~Controller() override;


	/**
* \Set linked MovementComponent
* \return void
*/
	void SetMovementComponent(MovementComponent* movementComponent) {
		this->movementComponent = movementComponent;
	}

	/**
 * \brief get all axis component as 2D vector
 * \return axis vector
 */
	[[nodiscard]] sf::Vector2f Get_Axis_Vector() { return { XAxis, YAxis }; }
};

	