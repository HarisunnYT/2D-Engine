#pragma once

#ifndef COLLISION_H
#define COLLISION_H

#include "EngineCore.h"

#include <vector>

class Collider;
class Collision
{
public:

	static bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB);
	static bool AABB(Collider& colA, Collider& colB);

	static vector<Collider*> colliders;

};

#endif