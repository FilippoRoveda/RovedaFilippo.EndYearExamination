#include "MusicComponent.h"

MusicComponent::MusicComponent(const std::string musicPath, bool isLooping, float volume, bool playOnStart) : Component ("Music component")
{
	music = new sf::Music();
	music->openFromFile(musicPath);
	music->setLoop(isLooping);
	music->setVolume(volume);
	this->playOnStart = playOnStart;
}

