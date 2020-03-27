#pragma once

#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include "Components.h"
#include "SDL.h"

class Transform;
class SpriteRenderer : public Component
{
public:

	SpriteRenderer() = default;
	SpriteRenderer(const char* path);

	void Init() override;
	void Update() override;
	void Draw() override;
	void SetTexture(const char* path);

private:

	Transform*		transform;

	SDL_Texture*	texture;

	SDL_Rect		sourceRect;
	SDL_Rect		destinationRect;

};

#endif