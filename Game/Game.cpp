#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "ECS.h"
#include "Components.h"

#include <iostream>

Map* map = nullptr;

Entity* player = nullptr;

Game::Game()
{
	map = new Map();
	player = &EngineCore::Ecs->AddEntity();

	player->AddComponent<Transform>();
	player->AddComponent<SpriteRenderer>("Assets/Player.png");
}

Game::~Game()
{
}

void Game::Update()
{
	//player.GetComponent<Transform>().Position = Vector3(500.0f, 0, 0);
}

void Game::Render()
{
	map->DrawMap();
}
