#include "AIMovement.h"

AIMovement::AIMovement() : Component("AI Movement")
{
	seekStrAl = new SeekSteeringAlgorythm();
}

void AIMovement::GetTarget()
{
	if (context->allEntities.size() == 0)
	{
		printf("No character found in scene!\n");
	}
	else {
		for (GameObject* entity : context->allEntities)
		{
			const auto val = dynamic_cast<Character*>(entity);
			if (!val) continue;
			else { 
				target = val; 
				hasTarget = true;
				seekStrAl->Construct(myTransform, target, maxSpeed, radius);
				break; 
			};
		}
	}
}

AIMovement::~AIMovement()
{
	delete seekStrAl;
	delete myTransform;
}

void AIMovement::On_Update(const float delta_time)
{
	seekStrAl->Construct(myTransform, target, maxSpeed, radius);
	//Moving using the only MovementAlgorith created at this moment
	if (!hasTarget) {
		printf("No character in scene!\n");
		return;
	}
	else
	{
		position = myTransform->GetTransform()->getPosition();
		myTransform->SetPosition(position.x + (velocity.x * delta_time), position.y + (velocity.y * delta_time));
		SteeringData* results = seekStrAl->GetSteering();

		if (results->reached) { 
			velocity = { 0, 0 }; 
		}

		else {
			velocity = velocity + results->linear * delta_time;
			myTransform->SetRotation(results->angular);
		}
		delete results;
	}
}
