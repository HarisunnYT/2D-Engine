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
Entity* tile = nullptr;

Game::Game()
{
	EngineCore::isDebug = true;
	Collision::drawGrid = false;

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
		for (auto& entity : EngineCore::Ecs->entities)
		{
			if (entity->HasComponent<Collider>() && entity->GetComponent<Collider>().Tag == "ground" && SDL_PointInRect(const_cast<SDL_Point*>(&InputSystem::MousePosition), const_cast<SDL_Rect*>(&entity->GetComponent<Collider>().collider)))
			{
				player->GetComponent<Rigidbody>().ForceAwake();
				entity->SetActive(false);
				break;
			}
		}
	}
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
