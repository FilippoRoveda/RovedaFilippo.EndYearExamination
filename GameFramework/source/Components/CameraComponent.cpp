#include "CameraComponent.h"
#include "Application.h"
#include "RectTransform.h"
#include <iostream>


CameraComponent::CameraComponent(sf::Vector2f center, sf::Vector2f size, Application* context, int priority, Character* owner) : Component("Camera component")
{
	cameraView = new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(0.0f, 0.0f));
	this->priority = priority;
	this->myChar = owner;
	auto xpos = myChar->rectTransform->GetTransform()->getPosition().x;
	auto ypos = myChar->rectTransform->GetTransform()->getPosition().y;
	this->context = context;
	cameraView->setCenter(center);
	cameraView->setSize(size);
	context->AddCameraInScene(this);
}


CameraComponent::~CameraComponent()
{
	//context->SetNextCamera(priority);
}

void CameraComponent::SetView()
{
	sf::View& cam = *(cameraView);
	context->currentCamera = this;
	context->_Window->setView(cam);
}



void CameraComponent::On_Update(const float delta_time)
{
	sf::View& cam = *(cameraView);
	if (abs(myChar->rectTransform->GetTransform()->getPosition().x - xpos) >= 5.0f)
	{
		xpos = myChar->rectTransform->GetTransform()->getPosition().x;
	}
	ypos = myChar->rectTransform->GetTransform()->getPosition().y;
	if (ypos < 300) { ypos = 300; }
	cameraView->setCenter(xpos,ypos);
	context->_Window->setView(cam);
}

void CameraComponent::On_Fixed_Update(const float delta_time)
{
	Component::On_Fixed_Update(delta_time);
}