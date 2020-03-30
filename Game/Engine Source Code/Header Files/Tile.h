#pragma once

#ifndef TILE_H
#define TILE_H

#include "EngineCore.h"
#include "TextureManager.h"

#include <vector>

class Tile : public Component
{
public:

	Tile() = default;
	Tile(const char* path, Vector3 position, Vector2 size, Vector2 source, float scale);
	~Tile();

	void Draw() override;

private:

	SDL_Texture*	texture;
	SDL_Rect		sourceRect;
	SDL_Rect		destinationRect;
};

#endif