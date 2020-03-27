#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Game.h"
#include "Vector3.h"

class GameObject
{
public:

	GameObject(const char* textureSheet, Vector3* pos);
	~GameObject();

	void Update();
	void Render();

private:

	Vector3*			position;

	SDL_Texture*	objectTexture;
	SDL_Rect		sourceRect;
	SDL_Rect		destinationRect;

};

#endif