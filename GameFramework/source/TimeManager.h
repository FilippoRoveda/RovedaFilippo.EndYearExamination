#pragma once
#include "SFML/System.hpp"
#include "dllclasses.h"

/**
 * \brief Utilitie struct to handle time.
 */
struct DECLSPEC TimeManager
{
public:
	TimeManager();
	virtual ~TimeManager();

	/// <summary>
	/// Return currentTime.
	/// </summary>
	/// <returns>current clock time</returns>
	sf::Time GetCurrentTime()const;


	/// <summary>
	/// Calculate delta between two time value.
	/// </summary>
	/// <returns>delta time</returns>
	static float CalculateElapsedTime(float currentTime, float lastTime);

private:
	sf::Clock clock;
};