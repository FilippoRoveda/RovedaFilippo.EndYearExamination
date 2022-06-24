#include "CameraComponent.h"
#include "Application.h"
#include "RectTransform.h"
#include <iostream>


CameraComponent::CameraComponent(sf::Vector2f center, sf::Vector2f size, Application* context, int priority, Character* owner) : Component("Camera component")
{
	cameraView = new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(0.0f, 0.0f));
	this->priority = priority;
	this->myChar = owner;
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
	context->_Window->setView(cam);
}



void CameraComponent::On_Update(const float delta_time)
{
	sf::View& cam = *(cameraView);
	cameraView->setCenter(myChar->rectTransform->GetTransform()->getPosition());
	context->_Window->setView(cam);
}

void CameraComponent::On_Fixed_Update(const float delta_time)
{
	Component::On_Fixed_Update(delta_time);
}