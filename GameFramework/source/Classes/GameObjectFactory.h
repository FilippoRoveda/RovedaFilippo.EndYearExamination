#pragma once
#include "Components/Collider.h"
#include "Components/MusicComponent.h"
#include "Classes/Character.h"
#include "Classes/MusicObject.h"
#include "Sprite.h"
#include "Components/AnimationComponent.h"
#include "Classes/Agent.h"

class GameObject;

/**
* \brief Abstract ObjectFactory that contains some base method for creation of default like
* entity in a 2D platform level.
*/
class GameObjectsFactory
{
protected:
	//Pointer to store created object
	GameObject* product = nullptr;
	Application* context = nullptr;

public:
	/**
	* \brief Defaul constructor.
	*/
	GameObjectsFactory() {};

	/**
	* \brief Constructor that set application context.
	*/
	GameObjectsFactory(Application* context) { this->context = context; };

	/**
	* \brief Default destructor.
		*/
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
	/**
	* \brief Constructor that set application context.
	*/
	FirstLevelFactory(Application* context) { this->context = context; };
	/**
	* \brief Default destructor.
	*/
	~FirstLevelFactory() {};


	/**
	* \brief Instantiate default platform block.
	*/
	 GameObject* NormalBlock(sf::Vector2f position) override;
	 /**
	* \brief Default backgorund layer.
	*/
	 GameObject* BackGround(sf::Vector2f position) override;
	 /**
	* \brief Background layer with a music track attached, this track starts with game session.
	*/
	 GameObject* BackGroundandMusic(sf::Vector2f position);
	 /**
	* \brief Collision ground layer with an enormous width, emulates a ground layer.
	*/
	 GameObject* GroundLayer() override;
	 /**
	* \brief Instantiate a Roman soldier with its animation that can be controlled by player.
	*/
	 GameObject* MainCharacter(sf::Vector2f position) override;
	 /**
	* \brief Instantiate an agent that seek one character in scene.
	*/
	 GameObject* Seeker(sf::Vector2f position) override;
};