#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "ECS.h"
#include "Components.h"

#include <iostream>

Map* map;

SDL_Renderer* Game::Renderer = nullptr;

ECS ecs;
auto& player(ecs.AddEntity());

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
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

	map = new Map();

	player.AddComponent<Transform>();
	player.AddComponent<SpriteRenderer>("Assets/Player.png");
}

void Game::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::Update()
{
	ecs.Refresh();
	ecs.Update();

	player.GetComponent<Transform>().Position = Vector3(500.0f, 0, 0);
}

void Game::Render()
{
	SDL_RenderClear(Renderer);

	map->DrawMap();
	ecs.Draw();

	SDL_RenderPresent(Renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(Renderer);
	SDL_Quit();
}

bool Game::Running()
{
	return isRunning;
}
