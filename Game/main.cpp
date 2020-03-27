#include "Game.h"

Game* game = nullptr;

const int FPS = 60;
const int frameDelay = 1000 / FPS;

int main(int agrc, char* argv[])
{
	game = new Game();
	game->Init("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	Uint32 frameStart;
	int frameTime;

	while (game->Running())
	{
		frameStart = SDL_GetTicks();

		game->HandleEvents();
		game->Update();
		game->Render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->Clean();

	return 0;
}