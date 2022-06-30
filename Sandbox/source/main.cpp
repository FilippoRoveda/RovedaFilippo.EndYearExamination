#include "application.h"
#include "Classes/GameObjectFactory.h"

int main() {

	Application* app = new Application();
	app->CreateWindow(1920, 1080, "RomanPlatform");
	app->SetMaxFPS(60);
	app->EnableFPSLimit();
	app->DisableFixedUpdate();

	auto sky = new Sprite();
	sky->renderer->SetTexturePath("source/resources/void.png", true, true);
	sky->rectTransform->SetScale(1000000, 3000);
	sky->rectTransform->SetPosition(-10000, -500);

	app->AddEntity(sky);
	auto factory = new FirstLevelFactory(app);
	app->AddEntity(factory->BackGroundandMusic(sf::Vector2f(0, 150)));
	app->AddEntity(factory->BackGround(sf::Vector2f(-1920, 150)));
	app->AddEntity(factory->BackGround(sf::Vector2f(-3840, 150)));
	app->AddEntity(factory->BackGround(sf::Vector2f(1920, 150)));
	app->AddEntity(factory->BackGround(sf::Vector2f(3840, 150)));
	app->AddEntity(factory->GroundLayer());

	app->AddEntity(factory->NormalBlock(sf::Vector2f(-400, 880)));
	app->AddEntity(factory->NormalBlock(sf::Vector2f(-400, 720)));
	app->AddEntity(factory->NormalBlock(sf::Vector2f(-400, 560)));
	app->AddEntity(factory->NormalBlock(sf::Vector2f(-400, 400)));
	app->AddEntity(factory->NormalBlock(sf::Vector2f(-400, 240)));
	app->AddEntity(factory->NormalBlock(sf::Vector2f(-400, 80)));
	app->AddEntity(factory->NormalBlock(sf::Vector2f(-400, -40)));
	app->AddEntity(factory->NormalBlock(sf::Vector2f(-400, -200)));
	app->AddEntity(factory->NormalBlock(sf::Vector2f(-400, -360)));


	app->AddEntity(factory->NormalBlock(sf::Vector2f(400, 700)));
	app->AddEntity(factory->NormalBlock(sf::Vector2f(800, 700)));
	app->AddEntity(factory->NormalBlock(sf::Vector2f(1200, 700)));
	app->AddEntity(factory->NormalBlock(sf::Vector2f(1600, 500)));
	app->AddEntity(factory->NormalBlock(sf::Vector2f(1800, 500)));
	app->AddEntity(factory->NormalBlock(sf::Vector2f(2200, 400)));
	app->AddEntity(factory->NormalBlock(sf::Vector2f(2700, 500)));
	app->AddEntity(factory->NormalBlock(sf::Vector2f(2900, 500)));
	app->AddEntity(factory->NormalBlock(sf::Vector2f(3100, 600)));
	app->AddEntity(factory->NormalBlock(sf::Vector2f(3300, 800)));
	app->AddEntity(factory->NormalBlock(sf::Vector2f(3500, 700)));
	app->AddEntity(factory->NormalBlock(sf::Vector2f(3500, 800)));
	app->AddEntity(factory->NormalBlock(sf::Vector2f(3800, 800)));
	
	app->AddEntity(factory->MainCharacter(sf::Vector2f(200, 600)));
	app->AddEntity(factory->Seeker(sf::Vector2f(-200, 200)));

	app->Run();

	return 0;
}