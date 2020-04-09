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

Entity* ground = nullptr;

Vector3 previousPlayerPosition;

Game::Game()
{
	EngineCore::isDebug = true;
	Collision::drawGrid = false;

	player = &EngineCore::Ecs->AddEntity("Assets/Prefabs/player");

	tileMap = new TileMap();
	tileMap->LoadMap("Assets/Map/map.map", "Assets/Map/tileset.png", Vector2(16, 16), Vector2(72, 11), 3.44f);

	EngineCore::camera->offset.x = static_cast<int>(player->transform->GetPosition().x);
}

Game::~Game()
{
}

void Game::Update()
{
	if (player->transform->GetPosition().x > EngineCore::screenSize.x / 2 && player->transform->GetRawPosition().x > previousPlayerPosition.x)
	{
		EngineCore::camera->offset.x = static_cast<int>(player->transform->GetRawPosition().x - (EngineCore::screenSize.x / 2));
	}
	previousPlayerPosition = player->transform->GetRawPosition();
}

void Game::LateUpdate()
{
}

void Game::Render()
{
}

void Game::Physics()
{
}

void Game::FixedUpdate()
{
	//EngineCore::camera->offset.x += 1;
}
