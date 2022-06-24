#pragma once
#include "Sprite.h"
#include "..\Components\Controller.h"
#include "..\Components\MovementComponent.h"

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