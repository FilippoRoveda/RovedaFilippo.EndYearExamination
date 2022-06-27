#include "GameObjectFactory.h"


	GameObject* FirstLevelFactory::NormalBlock(sf::Vector2f position)
	{
		auto product = new Sprite();
		product->renderer->SetTexturePath("source/resources/brick.jpg", true, true);
		auto c = new Collider(product->rectTransform, 1.0f);
		c->isMovable = false;
		product->Add_Component(c);
		product->rectTransform->SetScale(1, 1);
		product->rectTransform->SetPosition(position.x, position.y);
		product->rectTransform->GetTransform()->setSize(sf::Vector2f{ 200,122 });
		product->rectTransform->GetTransform()->setOrigin(sf::Vector2f{ 100, 61 });

		return product;
	}

	GameObject* FirstLevelFactory::BackGround(sf::Vector2f position)
	{
		auto product = new Sprite();
		product->renderer->SetTexturePath("source/resources/roma.jpg", true, true);
		product->rectTransform->SetScale(1920, 1080);
		auto soundTrack = new MusicComponent("source/resources/music1.wav", true, 60, true);
		product->rectTransform->SetPosition(position.x, position.y);
		product->Add_Component(soundTrack);

		return product;
	}

	GameObject* FirstLevelFactory::BackGroundandMusic(sf::Vector2f position)
	{
		auto product = new Sprite();
		product->renderer->SetTexturePath("source/resources/roma.jpg", true, true);
		product->rectTransform->SetScale(1920, 1080);
		auto soundTrack = new MusicComponent("source/resources/music1.wav", true, 80, true);
		product->rectTransform->SetPosition(position.x, position.y);
		product->Add_Component(soundTrack);

		return product;
	}

	GameObject* FirstLevelFactory::GroundLayer()
	{
		auto product = new Sprite();
		product->renderer->SetTexturePath("", true, true);
		auto collider = new Collider(product->rectTransform, 1.0f);
		collider->isMovable = false;
		product->Add_Component(collider);
		product->rectTransform->SetScale(1, 1);
		product->rectTransform->SetPosition(0, 900);
		product->rectTransform->GetTransform()->setSize(sf::Vector2f{ 1000000,2 });
		product->rectTransform->GetTransform()->setOrigin(sf::Vector2f{ 1000000 / 2, 1 });
		
		return product;
	}

	GameObject* FirstLevelFactory::MainCharacter(sf::Vector2f position)
	{
		auto product = new Character();
		product->renderer->SetTexturePath("source/resources/idle.png", true, true);
		product->rectTransform->GetTransform()->setTextureRect(sf::IntRect(0, 0, 168, 356));
		product->rectTransform->SetScale(1, 1);
		product->rectTransform->GetTransform()->setSize(sf::Vector2f{ 168,356 });
		product->rectTransform->GetTransform()->setOrigin(sf::Vector2f{ 168 / 2, 356 / 2 });
		product->movementComponent->speed = 200;
		product->rectTransform->SetPosition(position.x, position.y);
		product->movementComponent->SetRenderer(product->renderer);
		auto mainCamera = new CameraComponent(sf::Vector2f(860.0f, 540.0f), sf::Vector2f(1920.0f, 1080.0f), context, 0, product);
		product->Add_Component(mainCamera);
		auto anim = new AnimationComponent(product->rectTransform, sf::Vector2u(3, 1), 0.6f);
		product->Add_Component(anim);

		return product;
	}

	GameObject* FirstLevelFactory::Seeker()
	{
		auto product = new Agent(context);
		Collider* coll = new Collider(product->rectTransform, 1.0f);
		product->Add_Component(coll);
		product->renderer->SetTexturePath("source/resources/ghost.jpg", true, true);
		product->rectTransform->SetScale(256, 256);
		product->rectTransform->SetPosition(500, 0);

		return product;
	}
