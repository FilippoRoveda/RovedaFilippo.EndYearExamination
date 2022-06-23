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
	MusicComponent(std::string musicPath, bool isLooping, float volume, bool playOnStart);
	~MusicComponent() { delete music; }

	sf::SoundSource::Status GetStatus() { return music->getStatus(); }
	void Stop() { music->stop(); }
	void Play() { music->play(); }

};