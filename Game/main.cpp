#include "EngineCore.h"

EngineCore* engineCore = nullptr;

const int FPS = 60;
const int frameDelay = 1000 / FPS;

int main(int agrc, char* argv[])
{
	engineCore = new EngineCore();
	engineCore->Init("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	Uint32 frameStart;
	int frameTime;

	while (engineCore->Running())
	{
		frameStart = SDL_GetTicks();

		engineCore->HandleEvents();
		engineCore->Update();
		engineCore->Render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	engineCore->Clean();

	return 0;
}