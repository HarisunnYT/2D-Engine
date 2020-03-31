#include "Collision.h"
#include "Collider.h"

bool Collision::AABB(const SDL_Rect& rectA, const SDL_Rect& rectB)
{
	SDL_bool b = SDL_HasIntersection(&rectA, &rectB);
	return b;
}

bool Collision::AABB(Collider& colA, Collider& colB)
{
	return AABB(colA.GetCollider(), colB.GetCollider());
}
