#include "EngineCore.h"

EngineCore* engineCore = nullptr;

const int FPS = 60;
const int frameDelay = 1000 / FPS;

int main(int agrc, char* argv[])
{
	engineCore = new EngineCore();
	engineCore->Init("EngineCore", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, false);

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