#include "Game.h"
#include "TextureManager.h"
#include "TileMap.h"
#include "ECS.h"
#include "Components.h"
#include "SecondaryComponents.h"
#include "InputSystem.h"

#include <iostream>

TileMap* tileMap = nullptr;
Entity* player = nullptr;

Game::Game()
{
	player = &EngineCore::Ecs->AddEntity();
	player->AddComponent<PlayerController>();

	tileMap = new TileMap();
	tileMap->LoadMap("Assets/map.map", "Assets/terrain_ss.png", Vector2(16, 16), Vector2(16, 16), 3);
}

Game::~Game()
{
}

void Game::Update()
{
}

void Game::Render()
{
}
