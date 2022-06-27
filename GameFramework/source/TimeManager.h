#pragma once
#include "SFML/System.hpp"
struct TimeManager
{
public:
	TimeManager();
	virtual ~TimeManager();

	/// <summary>
	/// Return currentTime.
	/// </summary>
	/// <returns>current clock time</returns>
	sf::Time getCurrentTime()const;


	/// <summary>
	/// Calculate delta between two time value.
	/// </summary>
	/// <returns>delta time</returns>
	static float calculateElapsedTime(float currentTime, float lastTime);

private:
	sf::Clock clock;
};