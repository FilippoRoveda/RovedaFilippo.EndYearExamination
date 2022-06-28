#include "Application.h"



int main() {

	Application* app = new Application();
	app->CreateWindow(1920, 1080, "RomanPlatform");
	app->SetMaxFPS(60);
	app->EnableFPSLimit();
	app->DisableFixedUpdate();
	app->Run();

	return 0;
}