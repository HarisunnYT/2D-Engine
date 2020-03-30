#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
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
	Tile::AddTileTexture("assets/dirt.png");
	Tile::AddTileTexture("assets/grass.png");
	Tile::AddTileTexture("assets/water.png");

	tileMap = new TileMap();
	//tileMap->LoadMap("assets/pyxelmap_16x16.map", Vector2(16, 16));

	player = &EngineCore::Ecs->AddEntity();
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
