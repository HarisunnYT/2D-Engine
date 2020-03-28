#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "ECS.h"
#include "Components.h"
#include "GameComponents.h"

#include <iostream>

Map* map = nullptr;
Entity* player = nullptr;

Entity* wall;

Game::Game()
{
	map = new Map();

	player = &EngineCore::Ecs->AddEntity();
	player->AddComponent<SpriteRenderer>("Assets/Player.png", 128, 128);
	player->AddComponent<Collider>("player");
	player->AddComponent<PlayerController>();

	wall = &EngineCore::Ecs->AddEntity();
	wall->AddComponent<SpriteRenderer>("Assets/Dirt.png", 300, 300);
	wall->AddComponent<Collider>("wall");
	wall->GetComponent<Transform>().Position = Vector3(100, 50, 0);
	wall->GetComponent<Transform>().Scale = Vector2(1, 1);
}

Game::~Game()
{
}

void Game::Update()
{

}

void Game::Render()
{
	map->DrawMap();
}
