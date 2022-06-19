#include "Character.h"

Character::Character() : Sprite()
{
	controller = new Controller();
	Add_Component(controller);

	movementComponent = new MovementComponent();
	movementComponent->inputController = controller;
	movementComponent->transform = rectTransform;
	movementComponent->speed = 100;
	Add_Component(movementComponent);
}

Character::~Character()
{
	delete movementComponent;
	delete controller;
}


void Character::On_Update(const float delta_time)
{
	Sprite::On_Update(delta_time);
}

void Character::On_Fixed_Update(const float delta_time)
{
	Sprite::On_Fixed_Update(delta_time);
}