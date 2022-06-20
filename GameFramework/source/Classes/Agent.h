#include "Sprite.h"
#include "..\Components\AIMovement.h"
#include "..\Application.h"


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