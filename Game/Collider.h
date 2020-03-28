#pragma once

#ifndef COLLIDER_H
#define COLLIDER_H

#include "EngineCore.h"

#include <string>

class Transform;
class SpriteRenderer;

class Collider : public Component
{
public:

	Collider(std::string tag);

	void Init() override;
	void Update() override;

	SDL_Rect collider;
	std::string Tag;

private:

	Transform* transform = nullptr;
	SpriteRenderer* spriteRenderer = nullptr;

};

#endif