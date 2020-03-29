#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "TileMap.h"
#include "ECS.h"
#include "Components.h"
#include "GameComponents.h"

#include <iostream>

TileMap* tileMap = nullptr;
Entity* player = nullptr;

Game::Game()
{
	Tile::AddTileTexture("assets/Dirt.png");
	Tile::AddTileTexture("assets/Grass.png");
	Tile::AddTileTexture("assets/Water.png");

	tileMap = new TileMap();
	tileMap->LoadMap("assets/pyxelmap_16x16.map", Vector2(16, 16));

	player = &EngineCore::Ecs->AddEntity();
	player->AddComponent<SpriteRenderer>("Assets/Player.png", Vector2(16, 64));
	player->AddComponent<Collider>("player");
	player->AddComponent<PlayerController>();
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
