#pragma once
#include "Component.h"
#include "SFML/Graphics.hpp"
#include "Classes/Character.h"

class Application;

/**
* \brief CameraComponent, create, set, and handle the cameraView, if attached to a movable Character it's position can
* be updated in time.
*/
class CameraComponent : public Component
{
	friend class Application;

private:
	sf::View* cameraView;
	Application* context;
	Character* myChar;
	int priority;

	float xpos = 0.0f;
	float ypos = 0.0f;

public:
	float maxHeight = 300.0f;
	float minDeltaXPos = 5.0f;

protected:

	/**
	* \brief Update the position of the view center based on the character movement.
	* If delta position is too small the camera remains in the same position.
	* \return void
	*/
	void On_Update(const float delta_time) override;

	void On_Fixed_Update(const float delta_time) override;

public:
	
	/**
	* \brief Constructor.
	* Set contexts, initialize view and its position and add that in scene.
	* \return void
	*/
	CameraComponent(sf::Vector2f center, sf:: Vector2f size, Application* context, int priority, Character* owner);
	
	/**
	* \brief Destructor.
	* \return void
	*/
	~CameraComponent() {
		delete cameraView;
	};

	
	/**
	* \brief Set this cameraView fore the context application _Window member.
	* \return void
	*/
	void SetView();
};