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
	EngineCore::isDebug = false;

	player = &EngineCore::Ecs->AddEntity("Assets/Prefabs/player");
	player->GetComponent<Animator>().PlayAnimation(1);

	tileMap = new TileMap();
	tileMap->LoadMap("Assets/map2.map", "Assets/terrain_ss.png", Vector2(16, 16), Vector2(77, 16), 3.5f);
}

Game::~Game()
{
}

void Game::Update()
{
	if (InputSystem::MousePressed())
	{
		for (auto& c : EngineCore::Ecs->transforms)
		{
			if (c->entity->HasComponent<Collider>() && SDL_PointInRect(const_cast<SDL_Point*>(&InputSystem::MousePosition), const_cast<SDL_Rect*>(&c->entity->GetComponent<Collider>().collider)))
			{
				c->scale *= 0;
			}
		}
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
