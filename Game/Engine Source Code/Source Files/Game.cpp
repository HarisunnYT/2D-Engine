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
Entity* grassTile = nullptr;

Game::Game()
{
	EngineCore::isDebug = true;

	player = &EngineCore::Ecs->AddEntity("Assets/Prefabs/player");
	player->GetComponent<Animator>().PlayAnimation(1);

	tileMap = new TileMap();
	tileMap->LoadMap("Assets/map.map", "Assets/terrain_ss.png", Vector2(16, 16), Vector2(16, 16), 3.5f);

	//grassTile = &EngineCore::Ecs->AddEntity();
	//grassTile->AddComponent<Tile>("Assets/terrain_ss.png", Vector3(0, 0, 0), Vector2(16, 16), Vector2(3 * 16, 0 * 16), 3.5f);

	//ground = &EngineCore::Ecs->AddEntity("Assets/Prefabs/ground");
}

Game::~Game()
{
}

void Game::Update()
{
	if (InputSystem::KeyPressed(SDLK_SPACE))
	{
		//grassTile->SaveToDisk("Assets/Prefabs/Tiles/");
	}
}

void Game::Render()
{
}

void Game::Physics()
{
	Vector2 velocity = player->GetComponent<Rigidbody>().GetVelocity();
	SDL_Rect playerCol = player->GetComponent<Collider>().GetCollider();

	for (auto& c : EngineCore::Ecs->transforms)
	{
		Collider* col = &c->entity->GetComponent<Collider>();
		if (col != nullptr && col->Tag == "ground")
		{
			if (Collision::AABB(col->GetCollider(), playerCol))
			{
				if (velocity.y < 0)
				{
					velocity.y = 0;
				}
				player->GetComponent<Rigidbody>().SetVelocity(velocity);
			}
		}
	}
}
