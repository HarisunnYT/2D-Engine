#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "TileMap.h"
#include "ECS.h"
#include "Components.h"
#include "SecondaryComponents.h"

#include <iostream>

TileMap* tileMap = nullptr;
Entity* player = nullptr;

Game::Game()
{
	Tile::AddTileTexture("assets/Dirt.png");
	Tile::AddTileTexture("assets/Grass.png");
	Tile::AddTileTexture("assets/Water.png");

	tileMap = new TileMap();
	//tileMap->LoadMap("assets/pyxelmap_16x16.map", Vector2(16, 16));

	player = &EngineCore::Ecs->AddEntity();
	player->AddComponent<Animator>("Assets/PlayerIdle.png", Vector2(200, 318), 3, 250);
	player->AddComponent<Collider>("player");
	player->AddComponent<PlayerController>();
	player->GetComponent<Transform>().scale = Vector2(0.2f, 0.2f);
}

Game::~Game()
{
}

void Game::Update()
{
}

void Game::Render()
{
}
