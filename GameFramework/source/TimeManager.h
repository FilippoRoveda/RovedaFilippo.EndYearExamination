#pragma once
#include "SFML/System.hpp"
struct TimeManager
{
public:
	TimeManager();
	virtual ~TimeManager();

	sf::Time getCurrentTime()const;

	static float calculateElapsedTime(float currentTime, float lastTime);

private:
	sf::Clock clock;
};