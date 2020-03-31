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

	player = &EngineCore::Ecs->AddEntity();
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
	//EngineCore::Camera.x = static_cast<int>(player->GetComponent<Transform>().GetPosition().x - (EngineCore::screenSize.x / 2));
	//EngineCore::Camera.y = static_cast<int>(player->GetComponent<Transform>().GetPosition().y - (EngineCore::screenSize.y / 2));
}

void Game::Render()
{
}

void Game::Physics()
{
	previousPlayerPosition = player->GetComponent<Transform>().GetPosition();
	SDL_Rect playerCol = player->GetComponent<Collider>().GetCollider();

	for (auto& c : EngineCore::Ecs->transforms)
	{
		Collider* col = &c->Entity->GetComponent<Collider>();
		if (col != nullptr && col->Tag == "ground")
		{
			if (Collision::AABB(col->GetCollider(), playerCol))
			{
				player->GetComponent<Rigidbody>().SetVelocity(Vector2(0, 0));
			}
		}
	}
}
