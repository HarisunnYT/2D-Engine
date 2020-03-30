#pragma once

#ifndef MAP_H
#define MAP_H

#include "EngineCore.h"

class TileMap
{
public:

	TileMap();
	~TileMap();

	void LoadMap(std::string path, Vector2 size);

	void AddTile(int id, Vector3 position);

private:
};

#endif