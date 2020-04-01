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

Game::Game()
{
	EngineCore::isDebug = false;

	player = &EngineCore::Ecs->AddEntity("Assets/player.txt");
	player->AddComponent<PlayerController>();

	tileMap = new TileMap();
	tileMap->LoadMap("Assets/map.map", "Assets/terrain_ss.png", Vector2(16, 16), Vector2(16, 16), 3.5f);

	ground = &EngineCore::Ecs->AddEntity();
	ground->AddComponent<Collider>("ground");
	ground->GetComponent<Collider>().SetSize(Vector2(1000, 100));
	ground->GetComponent<Transform>().SetPosition(&Vector3(0, 505, 0));
}

Game::~Game()
{
}

void Game::Update()
{
	//TODO remove
	if (InputSystem::KeyPressed(SDLK_SPACE))
	{
		player->SaveToDisk("Assets/Prefabs/player");
	}

	//EngineCore::Camera.x = static_cast<int>(player->GetComponent<Transform>().GetPosition().x - (EngineCore::screenSize.x / 2));
	//EngineCore::Camera.y = static_cast<int>(player->GetComponent<Transform>().GetPosition().y - (EngineCore::screenSize.y / 2));
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
