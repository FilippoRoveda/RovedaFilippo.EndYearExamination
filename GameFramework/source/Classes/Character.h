#pragma once
#include "Sprite.h"
#include "..\Components\Controller.h"
#include "..\Components\MovementComponent.h"


/**
* \brief Sprite gameobject that contain by default a Controller component to receive inputs,
* a MovementComponent to handle those inputs and move the RectTranform that already own and 
* a collider to detect scene collision.
*/
class Character : public Sprite
{
	friend class Application;

protected:
	void On_Update(const float delta_time) override;
	void On_Fixed_Update(const float delta_time) override;

public:
	Character();
	~Character() override;
public:
	Controller* controller;
	MovementComponent* movementComponent;
	Collider* collider;
};