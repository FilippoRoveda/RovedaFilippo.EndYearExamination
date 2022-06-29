#include "Component.h"
#include "..\Components\RectTransform.h"
#include "AIAlgorithm/SeekSteering.h"
#include "..\Application.h"
#include "..\Classes\Character.h"
#include "dllclasses.h"


/**
 * \brief Component that move Agent object with a RectTransform component inside the world scene
 * \following directories given by a MovementAlgorithm.
 */
class DECLSPEC AIMovement : public Component
{
	friend class Application;

public:
	Application* context = nullptr;

	//Ref to moved entity.
	RectTranform* myTransform = nullptr;
	//Current implemented algorythm.
	SeekSteeringAlgorythm* seekStrAl = nullptr;
	//Target to seek.
	Character* target = nullptr;

private:
	//Bool that indicate if there is a Character to seek in scene.
	bool hasTarget = false;

protected:
	float maxSpeed = 100;
	float radius = 200;
	sf::Vector2f position;
	float orientation = 0.0f;
	sf::Vector2f velocity = {0, 0};
	float rotation = 0.0f;


public:
	/**
	* \brief Constructor, initialize seekStrAl.
	* \return void
	*/
	AIMovement();
	/**
	* \brief Destructor.
	* \return void
	*/
	~AIMovement() override;


	/**
	* \brief Detect character in scene and pass his information to the SeekAlgorythm to update all references.
	* \return void
	*/
	void GetTarget();

protected:
	/**
	* \brief Update handled entity position reciving data from SeekSteeringAlgorythm.
	* \return void
	*/
	void On_Update(const float delta_time) override;

};