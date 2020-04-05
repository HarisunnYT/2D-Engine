#pragma once

#ifndef COLLISION_H
#define COLLISION_H

#include "EngineCore.h"

#include <vector>
#include <list>

class Collider;
class Collision
{
public:

	static void Init();
	static void DebugDraw();

	static void UpdateGrid(Collider* collider);
	static void CheckCollision(Collider* collider);

	static bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB);
	static bool AABB(Collider& colA, Collider& colB);

	static vector<pair<SDL_Rect, vector<Collider*>>> grid;

	static bool drawGrid;
};

#endif