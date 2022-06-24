#pragma once
#include "SFML/Graphics.hpp"
#include "TimeManager.h"
#include"Classes/GameObject.h"
#include"Components/CameraComponent.h"



class Application
{
	friend class CameraComponent;

private:
	sf::Color backgroundcolor;
	TimeManager tm;

	sf::Time lastTime, currentTime;
	float elapsedTime;
	float lag;

	bool fixedUpdateEnabled;
	float msForFixedUpdate;

	bool fpsLimitEnabled;
	unsigned maxFPS;

protected:
	sf::RenderWindow* _Window;
public:
	std::vector<GameObject*> allEntities;
	std::vector<CameraComponent*> cameraInScene;

public:
	Application();
	~Application();

	/// <summary>
	/// Creates application window
	/// </summary>
	/// <param name="windowWidth">the window width</param>
	/// <param name="windowHeight">the window height</param>
	/// <param name="windowTitle">window main title</param>
	void CreateWindow(float windowWidth, float windowHeight, const char* windowTitle);

	/// <summary>
	/// Get TRUE if the application should kill itself.
	/// </summary>
	/// <returns> TRUE or FALSE</returns>
	bool isRunning()const;

	/// <summary>
	// limit frame per seconds to a constant value (e.g. 60)
	/// </summary>
	/// <param name="limit"></param>
	void SetMaxFPS(unsigned limit) { maxFPS = limit; };

	/// <summary>
	/// Enabled the FPS limit
	/// </summary>
	void EnableFPSLimit() { fpsLimitEnabled = true; };
	/// <summary>
	/// Disable the FPS limit (enable infinite frames per second)
	/// </summary>
	void DisableFPSLimit() { fpsLimitEnabled = false; };

	/// <summary>
	/// Enable fixed update
	/// </summary>
	void EnableFixedUpdate() { fixedUpdateEnabled = true; };

	/// <summary>
	/// Disable fixed update
	/// </summary>
	void DisableFixedUpdate() { fixedUpdateEnabled = false; };

	/// <summary>
	/// Set the number of milliseconds for fixed update
	/// </summary>
	/// <param name="milliseconds">fixed update frequency - i.e. 0.016</param>
	void SetMillisecondsForFixedUpdate(float milliseconds) { msForFixedUpdate = milliseconds; };


	/// <summary>
	/// Set the background color from sf::Color type
	/// </summary>
	void SetBackgroundColor( sf::Color color);

	/// <summary>
	/// Set the background color from 3 RGB float value and a float alpha value
	/// </summary>
	void SetBackgroundColor(float red, float green, float blue, float alpha);



	/// <summary>
	/// Executes application lifecycle.
	/// </summary>
	void Run();

	/// <summary>
	/// Add a GameObject to allEntities vector in application.
	/// </summary>
	void AddEntity(GameObject* entity)
	{
		allEntities.push_back(entity);
	}

	/// <summary>
	/// Remove specific GameObject to allEntities vector in application.
	/// </summary>
	void RemoveEntity(GameObject* entity)
	{
		for (auto item : allEntities)
		{
			if (item == entity)
			{
				std::vector<GameObject*> buffer;
				for (auto item : allEntities)
				{
					if (item != entity)
					{
						buffer.push_back(item);
					}
				}
				allEntities = buffer;
				delete entity;
			}
		}
	}





	public:
		void AddCameraInScene(CameraComponent* camera);


	private:
		void SetSceneCamera();







//GameLoop functions
private:

	void UpdateGameTime();

	/// <summary>
	/// Calculate the total frames in one seconds by elapsed time
	/// </summary>
	/// <returns>total frames</returns>
	unsigned GetFrameRate()const;

	void ProcessWindowEvents();

	//void processInput();

	void FixedUpdate();
	void Update();

	void Draw();

	void Initialize();


	void CheckCollision();

	void PlayMusicsInScene();




};
