#pragma once
#include "Component.h"
#include "SFML/Graphics.hpp"
#include "Classes/Character.h"

class Application;
class CameraComponent : public Component
{
	friend class Application;

private:
	sf::View* cameraView;
	Application* context;
	Character* myChar;
	int priority;

protected:
	void On_Update(const float delta_time) override;
	void On_Fixed_Update(const float delta_time) override;

public:
	CameraComponent();
	CameraComponent(sf::Vector2f center, sf:: Vector2f size, Application* context, int priority, Character* owner);
	~CameraComponent();

	void SetView();
};