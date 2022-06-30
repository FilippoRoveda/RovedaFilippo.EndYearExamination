#include "Agent.h"

Agent::Agent(Application* context)
{
	aiMovement = new AIMovement();
	aiMovement->myTransform = rectTransform;
	aiMovement->context = context;
	aiMovement->GetTarget();
	this->context = context;
	Add_Component(aiMovement);
}

Agent::~Agent()
{
	delete aiMovement;
}

void Agent::On_Update(const float delta_time)
{
	Sprite::On_Update(delta_time);
}

void Agent::On_Fixed_Update(const float delta_time)
{
	Sprite::On_Fixed_Update(delta_time);
}