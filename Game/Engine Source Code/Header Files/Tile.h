#pragma once

#ifndef TILE_H
#define TILE_H

#include "EngineCore.h"

#include <vector>

class Tile : public Component
{
public:

	Tile() = default;
	Tile(Vector3 position, Vector2 size, int id);

	void Init() override;

	static void AddTileTexture(const char* path);

	static vector<char*> tileTypes;

private:

	Transform*			transform;
	SpriteRenderer*		spriteRenderer;

	SDL_Rect			tileRect;
	char*				path;
	int					tileID;

	char* GetPath(int id);
};

#endif