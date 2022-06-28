#include "Character.h"

Character::Character() : Sprite()
{
	controller = new Controller();
	movementComponent = new MovementComponent();
	controller->SetMovementComponent(movementComponent);
	movementComponent->inputController = controller;
	movementComponent->transform = rectTransform;
	movementComponent->speed = 100;
	movementComponent->SetOwner(this);
	collider = new Collider(rectTransform, 1.0f);
	//collider->isMovable = false;
	movementComponent->SetCollider(collider);

	Add_Component(collider);
	Add_Component(controller);
	Add_Component(movementComponent);
}

Character::~Character()
{
	delete movementComponent;
	delete controller;
	delete collider;
}


void Character::On_Update(const float delta_time)
{
	Sprite::On_Update(delta_time);
}

void Character::On_Fixed_Update(const float delta_time)
{
	Sprite::On_Fixed_Update(delta_time);
}