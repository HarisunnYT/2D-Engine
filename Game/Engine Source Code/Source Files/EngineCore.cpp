#include "EngineCore.h"
#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Components.h"

#include <iostream>

SDL_Renderer* EngineCore::Renderer = nullptr;
SDL_Event EngineCore::Event;

ECS* EngineCore::Ecs = nullptr;

Game* game = nullptr;

EngineCore::EngineCore()
{
}

EngineCore::~EngineCore()
{
}

void EngineCore::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		int flags = 0;
		if (fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		Renderer = SDL_CreateRenderer(window, -1, 0);

		SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	Ecs = new ECS();
	game = new Game();
}

void EngineCore::HandleEvents()
{
	SDL_PollEvent(&Event);
	switch (Event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void EngineCore::Update()
{
	Ecs->Refresh();
	Ecs->Update();

	game->Update();
}

void EngineCore::Render()
{
	SDL_RenderClear(Renderer);

	game->Render();
	Ecs->Draw();

	SDL_RenderPresent(Renderer);
}

void EngineCore::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(Renderer);
	SDL_Quit();
}

bool EngineCore::Running()
{
	return isRunning;
}
