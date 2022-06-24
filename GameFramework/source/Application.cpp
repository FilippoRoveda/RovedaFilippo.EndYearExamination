#include "Application.h"
#include "Components/Component.h"
#include "Classes/IDrawable.h"
#include "Components/RectTransform.h"
#include "Classes/Sprite.h"
#include "Classes/Character.h"
#include "Classes/Agent.h"
#include "Components/Collider.h"
#include "Components/MusicComponent.h"
#include "Classes/MusicObject.h"


#include "iostream"
#include "SFML/Graphics.hpp"



Application::Application()
{
	_Window = nullptr;
	fpsLimitEnabled = false;
	maxFPS = 0;
	backgroundcolor = sf::Color::Black;
}

Application::~Application()
{
	delete this;
}



/// <summary>
/// Creates application window
/// </summary>
/// <param name="windowWidth">the window width</param>
/// <param name="windowHeight">the window height</param>
/// <param name="windowTitle">window main title</param>
void Application::CreateWindow(float windowWidth, float windowHeight, const char* windowTitle)
{
	_Window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), windowTitle);
	if (!_Window)
	{
		std::cerr << "Application window initialization failed\n";
		return;
	}
}
/// <summary>
/// Return TRUE if application's window is still open.
/// </summary>
/// <returns> TRUE or FALSE</returns>
bool Application::isRunning() const
{
	return _Window->isOpen();
}


/// <summary>
/// Set background coloro using sf::Color class.
/// </summary>
/// <returns></returns>
void Application::SetBackgroundColor(sf::Color color)
{
	backgroundcolor = color;
}
/// <summary>
/// Set background coloro using 4 float value for color component: red, green, blue, alpha.
/// </summary>
/// <returns></returns>
void Application::SetBackgroundColor(float red, float green, float blue, float alpha)
{
	backgroundcolor = sf::Color(red, green, blue, alpha);
}




/// <summary>
/// Add a CameraComponent to cameraInScene array that stores all view camera actually in scene.
/// </summary>
/// <returns></returns>
void Application::AddCameraInScene(CameraComponent* camera)
{
	allCameraInScene.push_back(camera);
}


/// <summary>
/// Set the current View of the _Window member of apllication based on priority.
/// priority is a member of CameraComponent class.
/// </summary>
/// <returns></returns>
void Application::SetSceneCamera()
{
	int counter = 0;
	bool completed = false;
	CameraComponent* cam;
	while (completed == true)
	{
		for (auto item : allCameraInScene)
		{
			if (item->priority <= counter)
			{
				item->SetView();
				completed = true;
				return;
			}
		}
		counter++;
		if (counter > 10) { return; }
	}
}



////
////	GameLoop functions
////
void Application::UpdateGameTime()
{
	currentTime = tm.getCurrentTime();
	elapsedTime = TimeManager::calculateElapsedTime(currentTime.asSeconds(), lastTime.asSeconds());
	lag += elapsedTime;
	lastTime = currentTime;
}

/// <summary>
/// Calculate the total frames in one seconds by elapsed time
/// </summary>
/// <returns>total frames</returns>
unsigned Application::GetFrameRate()const { return 1 / elapsedTime; }

void Application::ProcessWindowEvents()
{
	sf::Event evt{};
	while (_Window->pollEvent(evt))
	{
		if (evt.type == sf::Event::EventType::Closed)
		{
			_Window->close();
		}
		if (evt.type == sf::Event::EventType::Resized)
		{
			ResizeView();
		}
	}
}

void Application::ResizeView()
{
	float aspectRatio = float(_Window->getSize().x) / float(_Window->getSize().y);
	if (currentCamera != nullptr) {
		currentCamera->cameraView->setSize(currentCamera->cameraView->getSize().x / aspectRatio, currentCamera->cameraView->getSize().y / aspectRatio);
	}
}

void Application::FixedUpdate()
{
	for (auto item : allEntities)
	{
		if (item->isActive && item->Is_Tick_Enabled()) item->On_Fixed_Update(elapsedTime);
	}
}

void Application::Update()
{
	for (GameObject* item : allEntities)
	{
		if (item->isActive && item->Is_Tick_Enabled()) item->On_Update(elapsedTime);
	}
}


void Application::Draw()
{
	_Window->clear(backgroundcolor);

	for (auto item : allEntities)
	{
		const auto renders = item->Get_Components<RectTranform>();

		for (auto rend : renders)
		{
			_Window->draw(*rend->GetTransform());
		}
	}

	_Window->display();
}

void Application::Initialize()
{
	auto background = new Sprite();
	background->renderer->SetTexturePath("source/resources/roma.jpg", true, true);
	background->rectTransform->SetScale(1920, 1080);
	auto soundTrack = new MusicComponent("source/resources/music1.wav", true, 100, true);
	background->Add_Component(soundTrack);
	allEntities.push_back(background);

	auto groundLayer = new Sprite();
	groundLayer->renderer->SetTexturePath("", true, true);
	auto collider = new Collider(groundLayer->rectTransform, 1.0f);
	collider->isMovable = false;
	groundLayer->Add_Component(collider);
	groundLayer->rectTransform->SetScale(1, 1);
	groundLayer->rectTransform->SetPosition(1000, 800);
	groundLayer->rectTransform->GetTransform()->setSize(sf::Vector2f{10000000000,2});
	groundLayer->rectTransform->GetTransform()->setOrigin(sf::Vector2f{ 10000000000/2, 1 });
	allEntities.push_back(groundLayer);

	/*auto wa = new Sprite();
	wa->renderer->SetTexturePath("", true, true);
	auto c = new Collider(wa->rectTransform, 0.0f);
	wa->Add_Component(c);
	wa->rectTransform->SetScale(1, 1);
	wa->rectTransform->SetPosition(500, 800);
	wa->rectTransform->GetTransform()->setSize(sf::Vector2f{ 200,1000 });
	wa->rectTransform->GetTransform()->setOrigin(sf::Vector2f{ 100, 1000 / 2 });
	allEntities.push_back(wa);

	auto w = new Sprite();
	w->renderer->SetTexturePath("", true, true);
	auto i = new Collider(w->rectTransform, 0.0f);
	w->Add_Component(i);
	w->rectTransform->SetScale(1, 1);
	w->rectTransform->SetPosition(1500, 200);
	w->rectTransform->GetTransform()->setSize(sf::Vector2f{ 200,1000 });
	w->rectTransform->GetTransform()->setOrigin(sf::Vector2f{ 100, 1000 / 2 });
	allEntities.push_back(w);*/

	auto mainPG = new Character();
	mainPG->renderer->SetTexturePath("source/resources/duce.jpg", true, true);
	mainPG->rectTransform->SetScale(1, 1);
	mainPG->rectTransform->GetTransform()->setSize(sf::Vector2f{ 185,300 });
	mainPG->rectTransform->GetTransform()->setOrigin(sf::Vector2f{ 185 / 2, 300 / 2 });
	mainPG->movementComponent->speed = 200;
	mainPG->rectTransform->SetPosition(800, 400);
	auto mainCamera = new CameraComponent(sf::Vector2f(860.0f,540.0f),sf::Vector2f(1920.0f,1080.0f), this, 0, mainPG);
	mainPG->Add_Component(mainCamera);

	allEntities.push_back(mainPG);

	/*auto seeker = new Agent(this);
	Collider* coll = new Collider(seeker->rectTransform, 1.0f);
	seeker->Add_Component(coll);
	seeker->renderer->SetTexturePath("source/resources/hitler.jpg", true, true);
	seeker->rectTransform->SetScale(256, 256);
	seeker->rectTransform->SetPosition(500, 0);
	allEntities.push_back(seeker);*/
}

void Application::Run()
{
	Initialize();
	PlayMusicsInScene();
	SetSceneCamera();
	lastTime = tm.getCurrentTime();
	while (_Window->isOpen())
	{
		UpdateGameTime();
		//std::cout << "FPS: " << GetFrameRate() << std::endl;

		ProcessWindowEvents();
		if (fixedUpdateEnabled)
		{
			while (lag < msForFixedUpdate)
			{
				FixedUpdate();
				lag -= msForFixedUpdate;
			}
		}
		Update();
		CheckCollision();
		Draw();
		if (fpsLimitEnabled)
		{
			sf::sleep(sf::seconds((1.0f / maxFPS)));
		}
	}
}

void Application::CheckCollision() {

	std::vector<Collider*> colliders;

	for (auto item : allEntities)
	{
		if(item->Get_Component<Collider>()!=nullptr)
		{
			colliders.push_back(dynamic_cast<Collider*>(item->Get_Component<Collider>()));
		}
	}
	for (auto coll1 : colliders)
	{
		for (auto coll2 : colliders)
		{
			if (coll1 != coll2) {
				coll1->CheckCollision(coll2, coll2->push);
			}

		}
	}
}

void Application::PlayMusicsInScene()
{
	std::vector<MusicComponent*> musics;

	for (auto item : allEntities)
	{
		if (item->Get_Component<MusicComponent>() != nullptr)
		{
			musics.push_back(dynamic_cast<MusicComponent*>(item->Get_Component<MusicComponent>()));
		}
	}
	for (auto item : musics)
	{
		if (item->playOnStart == true)
		{
			item->Play();
		}
	}

	for (auto item : allEntities)
	{
		const auto val = dynamic_cast<MusicObject*>(item);
		if (!val) continue;
		else if (val->playOnStart == true)
		{
			val->Play();
		}
	}
}




