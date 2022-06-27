#pragma once
#include "Component.h"
#include "SFML/Audio.hpp"
#include <iostream>

class MusicComponent : public Component
{
	friend class Application;
private:
	sf::Music* music = nullptr;
	bool looping = false;
	float volume = 0;

protected:
	bool playOnStart = false;

public:
	/// <summary>
	///	Actual only constructor for this component.
	/// </summary>
	/// <returns></returns>
	MusicComponent(std::string musicPath, bool isLooping, float volume, bool playOnStart);
	~MusicComponent() { delete music; }

	/// <summary>
	///	Return current SoundSource::Status of sf::Music class in this component.
	/// </summary>
	/// <returns></returns>
	sf::SoundSource::Status GetStatus() { return music->getStatus(); }

	/// <summary>
///	Stop music from playing.
/// </summary>
/// <returns></returns>
	void Stop() { music->stop(); }


	/// <summary>
///	Start music.
/// </summary>
/// <returns></returns>
	void Play() { music->play(); }

};