#include "Game.h"
#include "TextureManager.h"
#include "TileMap.h"
#include "ECS.h"
#include "Components.h"
#include "SecondaryComponents.h"
#include "InputSystem.h"

#include <iostream>

TileMap* tileMap = nullptr;
TileMap* backgroundMap = nullptr;

Entity* player = nullptr;

Game::Game()
{
	EngineCore::isDebug = false;
	Collision::drawGrid = true;

	player = &EngineCore::Ecs->AddEntity("Assets/Prefabs/player");
	player->GetComponent<Animator>().PlayAnimation(1);

	backgroundMap = new TileMap();
	backgroundMap->LoadMap("Assets/bgmap.map", "Assets/terrain_ss.png", Vector2(16, 16), Vector2(77, 16), 3.5f);

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
			if (c->entity->HasComponent<Collider>() && c->entity->GetComponent<Collider>().Tag == "ground" && SDL_PointInRect(const_cast<SDL_Point*>(&InputSystem::MousePosition), const_cast<SDL_Rect*>(&c->entity->GetComponent<Collider>().collider)))
			{
				c->SetPosition(Vector3(10000, 0, 0));
			}
		}
	}
}

void Game::Render()
{
}

void Game::Physics()
{
}

void Game::FixedUpdate()
{
	EngineCore::camera->offset.x += 1;
}
