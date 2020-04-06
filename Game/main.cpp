#include "EngineCore.h"
#include <time.h>
#include "InputSystem.h"

EngineCore* engineCore = nullptr;

const int FPS = 60;
const int frameDelay = 100 / FPS;

float accumulatedTime;

void Tick(EngineCore* engineCore, float dTime)
{
	accumulatedTime += dTime;
	while (accumulatedTime > EngineCore::fixedTimeStep)
	{
		engineCore->FixedUpdate();
		accumulatedTime -= EngineCore::fixedTimeStep;
	}
}

int main(int agrc, char* argv[])
{
	engineCore = new EngineCore();
	engineCore->Init("EngineCore", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, false);

	int lastTime = clock();

	while (engineCore->Running())
	{
		int currentTime = clock();
		float dTime = (currentTime - lastTime) / (float)CLOCKS_PER_SEC;

		engineCore->HandleEvents();
		engineCore->Update(dTime);
		engineCore->Render();

		Tick(engineCore, dTime);

		lastTime = currentTime;
	}

	engineCore->Clean();

	return 0;
}