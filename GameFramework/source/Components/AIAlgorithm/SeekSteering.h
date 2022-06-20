#include "SFML/Graphics.hpp"
#include "..\RectTransform.h"
#include <..\source\Classes\Character.h>
#include "..\DataStruct.h"

class SeekSteeringAlgorithm {
public:
	SeekSteeringAlgorithm();
	~SeekSteeringAlgorithm();

	void Construct(RectTranform* agent, Character* target, float maxSpeed, float radius);

	SteeringData* GetSteering();
	float CalculateNewOrientation( sf::Vector2f velocity);

	float Vector2Lenght(sf::Vector2f vect);
	sf::Vector2f Normalize(sf::Vector2f vect);

protected:
	StaticData _character;
	StaticData _target;

public:
	float maxSpeed;
	float radius;
};


