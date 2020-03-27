#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "ECS.h"
#include "Components.h"
#include "GameComponents.h"

#include <iostream>

Map* map = nullptr;

Entity* player = nullptr;

Game::Game()
{
	map = new Map();
	player = &EngineCore::Ecs->AddEntity();

	player->AddComponent<SpriteRenderer>("Assets/Player.png");
	player->AddComponent<PlayerController>();
}

Game::~Game()
{
}

void Game::Update()
{
	
}

void Game::Render()
{
	map->DrawMap();
}
