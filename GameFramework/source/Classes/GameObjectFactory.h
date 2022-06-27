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

	virtual GameObject* NormalBlock() = 0;
	virtual GameObject* BackGround() = 0;
	virtual GameObject* GroundLayer() = 0;
	virtual GameObject* MainCharacter() = 0;
	virtual GameObject* Seeker() = 0;

};

class FirstLevelFactory : public GameObjectsFactory
{
public:
	FirstLevelFactory(Application* context) { this->context = context; };
	~FirstLevelFactory() {};

	 GameObject* NormalBlock() override;
	 GameObject* BackGround() override;
	 GameObject* GroundLayer() override;
	 GameObject* MainCharacter() override;
	 GameObject* Seeker() override;
};