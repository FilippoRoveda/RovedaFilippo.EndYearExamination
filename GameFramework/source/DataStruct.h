#pragma once
/**
 * \brief Static data struct for statics GameObjects.
 */
struct StaticData {
	sf::Vector2f position = { 0, 0 };
	float orientation = 0;
};


struct SteeringData {
	inline SteeringData(bool hasReached)
	{
		this->reached = hasReached;
	};
	sf::Vector2f linear = { 0, 0 };
	float angular = 0;
	bool reached = false;
};