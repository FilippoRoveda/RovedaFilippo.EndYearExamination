#pragma once
#include "TimeManager.h"

TimeManager::TimeManager() {}

TimeManager::~TimeManager() {}


/// <summary>
/// Return currentTime.
/// </summary>
/// <returns>current clock time</returns>
sf::Time TimeManager::GetCurrentTime()const
{
	return clock.getElapsedTime();
}


/// <summary>
/// Calculate delta between two time value.
/// </summary>
/// <returns>delta time</returns>
float TimeManager::CalculateElapsedTime(const float currentTime, const float lastTime)
{
	return currentTime - lastTime;
}