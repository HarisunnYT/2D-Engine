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
	EngineCore::isDebug = true;
	Collision::drawGrid = false;

	player = &EngineCore::Ecs->AddEntity("Assets/Prefabs/player");
	player->GetComponent<Animator>().PlayAnimation(1);

	//ground = &EngineCore::Ecs->AddEntity("Assets/Prefabs/ground");

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
				c->SetPosition(&Vector3(10000, 0, 0));
			}
		}
	}

	//EngineCore::camera->offset.x += 1;
}

void Game::Render()
{
}

void Game::Physics()
{
}

void Game::FixedUpdate()
{
}
