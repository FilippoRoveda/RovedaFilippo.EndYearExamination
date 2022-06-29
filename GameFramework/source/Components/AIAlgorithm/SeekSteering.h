#include "SFML/Graphics.hpp"
#include "..\RectTransform.h"
#include <..\source\Classes\Character.h>
#include "..\source\DataStruct.h"
#include "dllclasses.h"


/**
* \brief SeekSteering Kinematic algorythm, implement a radial detection that stops tha handled RectTransform from moving
* \ once target is reached.
*/
class DECLSPEC SeekSteeringAlgorythm {


protected:
	//Moved entity static data structure.
	StaticData _character;
	//Target entity static data structure.
	StaticData _target;

public:
	float maxSpeed;
	float radius;


public:
	/**
	* \ Default constructor.
	* \ return void
	*/
	SeekSteeringAlgorythm();
	/**
	* \ Denstructor.
	* \ return void
	*/
	~SeekSteeringAlgorythm();

	/**
	* \ Update all referenced objects data.
	* \ return void
	*/
	void Construct(RectTranform* agent, Character* target, float maxSpeed, float radius);

	/**
	* \ If the target isn't reached calculate new SteeringData struct.
	* \ return void
	*/
	SteeringData* GetSteering();

	/**
* \ Calculate new orientation for the seeker entity.
* \ return void
*/
	float CalculateNewOrientation( sf::Vector2f velocity);


	/**
* \ Utility to calculate a vector lenght.
* \ return void
*/
	float Vector2Lenght(sf::Vector2f vect);

	/**
* \ Utility that normalize a given vector.
* \ return void
*/
	sf::Vector2f Normalize(sf::Vector2f vect);

};


