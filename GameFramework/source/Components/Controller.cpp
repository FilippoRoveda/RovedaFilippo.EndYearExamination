
#include "..\Components\Component.h"
#include "..\Components\Controller.h"


void Controller::On_Update(const float delta_time)
{
	Component::On_Update(delta_time);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		forwardMovement = true;
		YAxis = -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		forwardMovement = true;
		YAxis = 1;
	}
	else
	{
		forwardMovement = false;
		YAxis = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rightwardMovement = true;
		XAxis = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rightwardMovement = true;
		XAxis = -1;
	}
	else
	{
		forwardMovement = false;
		XAxis = 0;
	}

	printf("axis: %f, %f \n", XAxis, YAxis);
}

void Controller::On_Fixed_Update(const float delta_time)
{
	Component::On_Fixed_Update(delta_time);

}

Controller::Controller() : Component ("Controller")
{
	forwardMovement = false;
	rightwardMovement = true;
	XAxis = 0;
	YAxis = 0;
}

Controller::~Controller() = default;

