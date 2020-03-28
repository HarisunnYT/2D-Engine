#pragma once

#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include "EngineCore.h"

class Transform;
class SpriteRenderer : public Component
{
public:

	SpriteRenderer(const char* path, int width, int height);
	~SpriteRenderer();

	void Init() override;
	void Update() override;
	void Draw() override;
	void SetTexture(const char* path);

	Vector2			SpriteSize;

private:

	Transform*		transform;

	SDL_Texture*	texture;

	SDL_Rect		sourceRect;
	SDL_Rect		destinationRect;

};

#endif