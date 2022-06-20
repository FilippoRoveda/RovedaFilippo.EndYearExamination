#include "SeekSteering.h"

SeekSteeringAlgorithm::SeekSteeringAlgorithm()
{
	maxSpeed = 0;
	radius = 0;
}

SeekSteeringAlgorithm::~SeekSteeringAlgorithm()
{
}

void SeekSteeringAlgorithm::Construct(RectTranform* agent, Character* target, float maxSpeed, float radius)
{
	_character.position = agent->GetTransform()->getPosition();
	_character.orientation = agent->GetTransform()->getRotation();
	_target.position = target->rectTransform->GetTransform()->getPosition();
	_target.orientation = target->rectTransform->GetTransform()->getRotation();
	this->maxSpeed = maxSpeed;
	this->radius = radius;
}

SteeringData* SeekSteeringAlgorithm::GetSteering()
{
	if (Vector2Lenght(_target.position - _character.position) < radius)
	{
		return new SteeringData(true);
	}
	else
	{
		sf::Vector2f velocity = (_target.position - _character.position);
		velocity = Normalize(velocity) * maxSpeed;
		SteeringData* results = new SteeringData(false);
		results->linear = velocity;
		results->angular = CalculateNewOrientation(velocity);
		return results;
	}
}

float SeekSteeringAlgorithm::CalculateNewOrientation( sf::Vector2f velocity)
{
	if (Vector2Lenght(velocity) > 0)
	{
	//Implementare rotazione, ottenere angolo da seno e coseno
		return _character.orientation;
	}
	else
	{
		return _character.orientation;
	}
}

float SeekSteeringAlgorithm::Vector2Lenght(sf::Vector2f vect)
{
	return std::sqrt(vect.x * vect.x + vect.y * vect.y);
}

sf::Vector2f SeekSteeringAlgorithm::Normalize(sf::Vector2f vect)
{
	float len = std::sqrt(vect.x * vect.x + vect.y * vect.y);
	if (len != 0) {
		sf::Vector2f normal = { vect.x / len, vect.y / len };
		return normal;
	}
}
