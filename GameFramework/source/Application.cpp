#include "Application.h"
#include "Components/Component.h"
#include "Classes/IDrawable.h"
#include "Components/RectTransform.h"
#include "Classes/Sprite.h";
#include "Classes/Character.h"
#include "Classes/Agent.h"


#include "iostream"
#include "SFML/Graphics.hpp"



Application::Application()
{
	_Window = nullptr;

	fpsLimitEnabled = false;
	maxFPS = 0;

	backgroundcolor = sf::Color::Black;

	//initialize();
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
	allEntities.push_back(background);

	auto dux = new Character();
	dux->renderer->SetTexturePath("source/resources/duce.jpg", true, true);
	dux->rectTransform->SetScale(185, 273);
	dux->movementComponent->speed = 200;
	allEntities.push_back(dux);

	auto runningDux = new Agent(this);
	runningDux->renderer->SetTexturePath("source/resources/duce.jpg", true, true);
	runningDux->rectTransform->SetScale(185, 273);
	allEntities.push_back(runningDux);
}

void Application::Run()
{
	Initialize();
	lastTime = tm.getCurrentTime();
	while (_Window->isOpen())
	{
		UpdateGameTime();
		std::cout << "FPS: " << GetFrameRate() << std::endl;

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
		Draw();
		if (fpsLimitEnabled)
		{
			sf::sleep(sf::seconds((1.0f / maxFPS)));
		}
	}
}




