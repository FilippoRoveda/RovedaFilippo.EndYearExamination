#include "Component.h"
#include "..\Components\RectTransform.h"
#include "AIAlgorithm/SeekSteering.h"
#include "..\Application.h"
#include "..\Classes\Character.h"


/**
 * \brief Component that move Agent object with a RectTransform component inside the world scene
 * \following directories given by a MovementAlgorithm.
 */
class AIMovement : public Component
{
	friend class Application;
public:
	Application* context = nullptr;
	RectTranform* myTransform;
	SeekSteeringAlgorithm* seekStrAl;
	Character* target;

private:
	bool hasTarget = false;

protected:
	float maxSpeed = 100;
	float radius = 200;
	sf::Vector2f position;
	float orientation;
	sf::Vector2f velocity = {0, 0};
	float rotation;


public:
	AIMovement();
	~AIMovement() override;

	void GetTarget();

	void On_Update(const float delta_time) override;

};