#pragma once
#include "Components/Collider.h"
#include "Components/MusicComponent.h"
#include "Classes/Character.h"
#include "Classes/MusicObject.h"
#include "Sprite.h"
#include "Components/AnimationComponent.h"
#include "Classes/Agent.h"


class GameObject;

class GameObjectsFactory
{
protected:
	GameObject* product = nullptr;
	Application* context = nullptr;

public:
	GameObjectsFactory() {};
	GameObjectsFactory(Application* context) { this->context = context; };
	~GameObjectsFactory() {};

	virtual GameObject* NormalBlock(sf::Vector2f position) = 0;
	virtual GameObject* BackGround(sf::Vector2f position) = 0;
	virtual GameObject* GroundLayer() = 0;
	virtual GameObject* MainCharacter(sf::Vector2f position) = 0;
	virtual GameObject* Seeker(sf::Vector2f position) = 0;

};

class FirstLevelFactory : public GameObjectsFactory
{
public:
	FirstLevelFactory(Application* context) { this->context = context; };
	~FirstLevelFactory() {};

	 GameObject* NormalBlock(sf::Vector2f position) override;
	 GameObject* BackGround(sf::Vector2f position) override;
	 GameObject* BackGroundandMusic(sf::Vector2f position);
	 GameObject* GroundLayer() override;
	 GameObject* MainCharacter(sf::Vector2f position) override;
	 GameObject* Seeker(sf::Vector2f position) override;
};