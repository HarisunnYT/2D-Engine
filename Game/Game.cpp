#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "TileMap.h"
#include "ECS.h"
#include "Components.h"
#include "GameComponents.h"

#include <iostream>

TileMap* tileMap = nullptr;
Entity* player = nullptr;

Entity* tile0 = nullptr;
Entity* tile1 = nullptr;
Entity* tile2 = nullptr;

Game::Game()
{
	tileMap = new TileMap();

	player = &EngineCore::Ecs->AddEntity();
	player->AddComponent<SpriteRenderer>("Assets/Player.png", Vector2(16, 64));
	player->AddComponent<Collider>("player");
	player->AddComponent<PlayerController>();

	tile0 = &EngineCore::Ecs->AddEntity();
	tile0->AddComponent<Tile>(Vector3(50, 0, 0), Vector2(1, 1), 0);
	tile0->AddComponent<Collider>("dirt");

	tile1 = &EngineCore::Ecs->AddEntity();
	tile1->AddComponent<Tile>(Vector3(114, 0, 0), Vector2(1, 1), 1);
	tile0->AddComponent<Collider>("grass");

	tile2 = &EngineCore::Ecs->AddEntity();
	tile2->AddComponent<Tile>(Vector3(178, 0, 0), Vector2(1, 1), 2);
	tile0->AddComponent<Collider>("water");
}

Game::~Game()
{
}

void Game::Update()
{
	if (Collision::AABB(player->GetComponent<Collider>(), tile0->GetComponent<Collider>()))
	{
		std::cout << "Yooo" << std::endl;
	}
}

void Game::Render()
{
	tileMap->DrawMap();
}
