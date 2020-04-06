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
Entity* particle = nullptr;

Game::Game()
{
	EngineCore::isDebug = false;
	Collision::drawGrid = false;

	player = &EngineCore::Ecs->AddEntity("Assets/Prefabs/player");
	player->GetComponent<Animator>().PlayAnimation(1);

	backgroundMap = new TileMap();
	backgroundMap->LoadMap("Assets/bgmap.map", "Assets/terrain_ss.png", Vector2(16, 16), Vector2(77, 13), 3.5f);

	tileMap = new TileMap();
	tileMap->LoadMap("Assets/map.map", "Assets/terrain_ss.png", Vector2(16, 16), Vector2(77, 13), 3.5f);

	particle = &EngineCore::Ecs->AddEntity();
	particle->AddComponent<Particle>("Assets/explosion.png", Vector2(96, 96), Vector2(10, 5), 10, 1);
	particle->SetActive(false);

}

Game::~Game()
{
}

void Game::Update()
{
	if (InputSystem::Mouse(SDL_BUTTON_LEFT))
	{
		for (auto& entity : EngineCore::Ecs->entities)
		{
			if (entity->HasComponent<Collider>() && entity->GetComponent<Collider>().Tag == "ground" && SDL_PointInRect(const_cast<SDL_Point*>(&InputSystem::MousePosition), const_cast<SDL_Rect*>(&entity->GetComponent<Collider>().collider)))
			{
				Vector3 targetPos = entity->transform->GetPosition();
				targetPos.x -= particle->GetComponent<Particle>().spriteSize.x / 4;
				targetPos.y -= particle->GetComponent<Particle>().spriteSize.y / 4;
				particle->SetActive(true);
				particle->transform->SetPosition(targetPos);

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
	EngineCore::camera->offset.x += 1;
}
