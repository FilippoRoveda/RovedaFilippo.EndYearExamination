#include "Application.h"
#include "Components/Component.h"
#include "Components/RectTransform.h"
#include "..\source\Classes\GameObjectFactory.h"

#include "iostream"
#include "SFML/Graphics.hpp"


/// <summary>
/// Default constructor, set _Window to nullptr, fpsLimitEnabled = false and maxFPS to 0.
/// </summary>
Application::Application()
{
	_Window = nullptr;
	fpsLimitEnabled = false;
	maxFPS = 0;
	backgroundcolor = sf::Color::Black;
}

/// <summary>
/// Default destructor.
/// </summary>
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


	/// <summary>
	/// Update currentTime, calculate elapsedTime, add lag and setLastTime as the last currentTime.
	/// </summary>
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


/// <summary>
/// Process all window events using sf::Event SFML class.
/// </summary>
/// <returns>total frames</returns>
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


/// <summary>
/// Resize the window view based on actual size of the window.
/// </summary>
/// <returns>total frames</returns>
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

/// <summary>
/// Render all transform in RectTranform components of all GameObjects in allEntities.
/// </summary>
/// <returns>total frames</returns>
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
	auto sky = new Sprite();
	sky->renderer->SetTexturePath("source/resources/void.png", true, true);
	sky->rectTransform->SetScale(10000000, 3000);
	sky->rectTransform->SetPosition(-10000,-500);
	AddEntity(sky);
	auto factory = new FirstLevelFactory(this);
	AddEntity(factory->BackGroundandMusic(sf::Vector2f(0, 150)));
	AddEntity(factory->BackGround(sf::Vector2f(-1920, 150)));
	AddEntity(factory->BackGround(sf::Vector2f(-3840, 150)));
	AddEntity(factory->BackGround(sf::Vector2f(1920, 150)));
	AddEntity(factory->BackGround(sf::Vector2f(3840, 150)));
	AddEntity(factory->GroundLayer());

	AddEntity(factory->NormalBlock(sf::Vector2f(-400, 880)));
	AddEntity(factory->NormalBlock(sf::Vector2f(-400, 720)));
	AddEntity(factory->NormalBlock(sf::Vector2f(-400, 560)));
	AddEntity(factory->NormalBlock(sf::Vector2f(-400, 400)));
	AddEntity(factory->NormalBlock(sf::Vector2f(-400, 240)));
	AddEntity(factory->NormalBlock(sf::Vector2f(-400, 80)));
	AddEntity(factory->NormalBlock(sf::Vector2f(-400, -40)));
	AddEntity(factory->NormalBlock(sf::Vector2f(-400, -200)));
	AddEntity(factory->NormalBlock(sf::Vector2f(-400, -360)));


	AddEntity(factory->NormalBlock(sf::Vector2f(400, 700)));
	AddEntity(factory->NormalBlock(sf::Vector2f(800, 700)));
	AddEntity(factory->NormalBlock(sf::Vector2f(1200, 700)));
	AddEntity(factory->NormalBlock(sf::Vector2f(1600, 400)));
	AddEntity(factory->NormalBlock(sf::Vector2f(2200, 400)));

	AddEntity(factory->MainCharacter(sf::Vector2f(200, 600)));
	AddEntity(factory->Seeker(sf::Vector2f(-200, 200)));

}


/// <summary>
/// Executes application lifecycle.
/// </summary>
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


/// <summary>
/// Check collision event between every GameObject thas has a collider.
/// </summary>
/// <returns>total frames</returns>
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


/// <summary>
/// Play music sound piece from all MusicComponents and MusicObjects.
/// </summary>
/// <returns>total frames</returns>
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




