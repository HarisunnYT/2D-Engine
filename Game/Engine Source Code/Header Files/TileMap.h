#pragma once

#ifndef MAP_H
#define MAP_H

#include "EngineCore.h"

class TileMap
{
public:

	TileMap();
	~TileMap();

	void LoadMap(std::string mapPath, const char* spriteSheetPath, Vector2 tileSize, Vector2 mapSize, float scale);
	void AddTile(const char* spriteSheetPath, Vector3 position, Vector2 size, Vector2 source, float scale);

private:

};

#endif