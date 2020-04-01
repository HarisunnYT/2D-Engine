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

Entity* wall = nullptr;

Game::Game()
{
	EngineCore::isDebug = false;

	player = &EngineCore::Ecs->AddEntity();
	player->AddComponent<Rigidbody>();
	player->AddComponent<PlayerController>();

	Animator* animator = &player->AddComponent<Animator>("Assets/player_sprite_sheet.png", Vector2(64, 69));
	animator->AddNewAnimation("WalkUp", 0, 8, 150);
	animator->AddNewAnimation("WalkLeft", 1, 8, 150);
	animator->AddNewAnimation("WalkDown", 2, 8, 150);
	animator->AddNewAnimation("WalkRight", 3, 8, 150);
	animator->PlayAnimation(0);

	player->GetComponent<Transform>().scale = Vector2(2.0f, 2.0f);
	player->GetComponent<Transform>().SetPosition(&Vector3(EngineCore::screenSize.x / 2, EngineCore::screenSize.y / 2, 1));

	Collider* collider = &player->AddComponent<Collider>("player");
	collider->SetSize(Vector2(30, 50));
	collider->SetOffset(Vector2(30, 20));

	tileMap = new TileMap();
	tileMap->LoadMap("Assets/map.map", "Assets/terrain_ss.png", Vector2(16, 16), Vector2(16, 16), 3.5f);

	ground = &EngineCore::Ecs->AddEntity("Assets/Prefabs/ground");
	
	wall = &EngineCore::Ecs->AddEntity("Assets/Prefabs/wall");

	//EngineCore::Ecs->LoadPrefab("Assets/Prefabs/player");
}

Game::~Game()
{
}

void Game::Update()
{
	//TODO remove
	if (InputSystem::KeyPressed(SDLK_SPACE))
	{
		wall->SaveToDisk("Assets/Prefabs/wall");
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
