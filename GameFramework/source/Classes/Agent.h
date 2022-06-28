#include "Sprite.h"
#include "..\Components\AIMovement.h"
#include "..\Application.h"

/**
* \brief Sprite gameobject that contain by default an AiMovement component to perform certain
*        movement algorythm to follow a target gameobject.
*/
class Agent : public Sprite
{
	friend class Application;

protected:
	void On_Update(const float delta_time) override;
	void On_Fixed_Update(const float delta_time) override;

public:
	Agent(Application* context);
	~Agent() override;

private:
	AIMovement* aiMovement;
	Application* context;
};