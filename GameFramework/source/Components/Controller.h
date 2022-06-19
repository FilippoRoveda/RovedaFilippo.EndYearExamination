#pragma once
#include "..\Components\Component.h"
#include "..\include\SFML\Graphics.hpp"

/**
*  /brief Component that manage device inputs
*/

class Controller : public Component
{
	friend class Application;
	friend class MovementComponent;

private:
	bool forwardMovement;
	bool rightwardMovement;
	float XAxis, YAxis;



protected:
	void On_Update(const float delta_time) override;
	void On_Fixed_Update(const float delta_time) override;

public:
	Controller();
	~Controller() override;

	/**
 * \brief get all axis component as 2D vector
 * \return axis vector
 */
	[[nodiscard]] sf::Vector2f Get_Axis_Vector()const { return { XAxis, YAxis }; }
};

	