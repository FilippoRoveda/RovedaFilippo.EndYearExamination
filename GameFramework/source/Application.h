#pragma once
#include "SFML/Graphics.hpp"
#include "TimeManager.h"
#include"Classes/GameObject.h"
#include"Components/CameraComponent.h"


/**
 * \brief Application class, contain every entity in scene, handle windows and views and runs the core application loop.
 */
class Application
{
	friend class CameraComponent;

private:
	sf::Color backgroundcolor;
	TimeManager tm;

	sf::Time lastTime, currentTime;
	float elapsedTime = 0.0f;
	float lag = 0.0f;

	bool fixedUpdateEnabled = false;
	float msForFixedUpdate = 0.016f;

	bool fpsLimitEnabled = false;
	unsigned maxFPS = 60;

protected:
	sf::RenderWindow* _Window = nullptr;
public:
	std::vector<GameObject*> allEntities;
	std::vector<CameraComponent*> allCameraInScene;
	CameraComponent* currentCamera = nullptr;

public:
	Application();
	~Application();

	/// <summary>
	/// Creates application window
	/// </summary>
	/// <param name="windowWidth">the window width</param>
	/// <param name="windowHeight">the window height</param>
	/// <param name="windowTitle">window main title</param>
	void CreateWindow(unsigned int windowWidth, unsigned int windowHeight, const char* windowTitle);

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
	void SetBackgroundColor(sf::Uint8 red, sf::Uint8 green, sf::Uint8 blue, sf::Uint8 alpha);



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


	/// <summary>
	/// Add a CameraComponent to cameraInScene array that stores all view camera actually in scene.
	/// </summary>
	/// <returns></returns>
	public:
		void AddCameraInScene(CameraComponent* camera);

	/// <summary>
	/// Set the current View of the _Window member of apllication based on priority.
	/// priority is a member of CameraComponent class.
	/// </summary>
	/// <returns></returns>
	private:
		void SetSceneCamera();







//GameLoop functions
private:

	/// <summary>
	/// Update currentTime, calculate elapsedTime, add lag and setLastTime as the last currentTime.
	/// </summary>
	void UpdateGameTime();

	/// <summary>
	/// Calculate the total frames in one seconds by elapsed time
	/// </summary>
	/// <returns>total frames</returns>
	unsigned GetFrameRate()const;


	/// <summary>
	/// Process all window events using sf::Event SFML class.
	/// </summary>
	/// <returns>total frames</returns>
	void ProcessWindowEvents();


	/// <summary>
	/// Resize the window view based on actual size of the window.
	/// </summary>
	/// <returns>total frames</returns>
	void ResizeView();



	void FixedUpdate();

	void Update();


	/// <summary>
	/// Render all transform in RectTranform components of all GameObjects in allEntities.
	/// </summary>
	/// <returns>total frames</returns>
	void Draw();

	void Initialize();


	/// <summary>
	/// Check collision event between every GameObject thas has a collider.
	/// </summary>
	/// <returns>total frames</returns>
	void CheckCollision();


	/// <summary>
	/// Play music sound piece from all MusicComponents and MusicObjects.
	/// </summary>
	/// <returns>total frames</returns>
	void PlayMusicsInScene();




};
