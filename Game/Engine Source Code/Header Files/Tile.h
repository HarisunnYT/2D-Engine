#pragma once

#ifndef TILE_H
#define TILE_H

#include "EngineCore.h"
#include "TextureManager.h"

#include <vector>

class Transform;
class Tile : public Component
{
public:

	Tile() = default;
	Tile(const char* path, Vector3 position, Vector2 size, Vector2 source, float scale);
	~Tile();

	void Init() override;
	void Update() override;
	void Draw() override;

private:

	SDL_Texture*	texture;
	SDL_Rect		sourceRect;
	SDL_Rect		destinationRect;

	Vector3			startingPosition;
	Vector2			startingScale;
	Vector2			size;

	Transform*		transform;

	Collider* collider;
};

#endif