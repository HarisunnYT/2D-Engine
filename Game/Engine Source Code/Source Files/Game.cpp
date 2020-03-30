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
	tileMap->LoadMap("Assets/map.map", "Assets/terrain_ss.png", Vector2(16, 16), Vector2(16, 16), 4);
}

Game::~Game()
{
}

void Game::Update()
{
	EngineCore::Camera.x = static_cast<int>(player->GetComponent<Transform>().position.x - (EngineCore::screenSize.x / 2));
	EngineCore::Camera.y = static_cast<int>(player->GetComponent<Transform>().position.y - (EngineCore::screenSize.y / 2));

	if (EngineCore::Camera.x < 0)
		EngineCore::Camera.x = 0;
	if (EngineCore::Camera.y < 0)
		EngineCore::Camera.y = 0;
	if (EngineCore::Camera.x > EngineCore::Camera.w)
		EngineCore::Camera.x = EngineCore::Camera.w;
	if (EngineCore::Camera.y > EngineCore::Camera.h)
		EngineCore::Camera.y = EngineCore::Camera.h;
}

void Game::Render()
{
}
