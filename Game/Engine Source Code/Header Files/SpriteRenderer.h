#pragma once

#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include "EngineCore.h"

class Transform;
class SpriteRenderer : public Component
{
public:

	SpriteRenderer(const char* path, Vector2 size);
	~SpriteRenderer();

	void Init() override;
	void Draw() override;
	void SetTexture(const char* path);

	Vector2			spriteSize;

protected:

	Transform*		transform;

	SDL_Texture*	texture;
	
	char*			currentPath;

	SDL_Rect		sourceRect;
	SDL_Rect		destinationRect;

};

#endif