#include "Collider.h"

vector<Collider*> Collision::colliders;

Collider::Collider(std::string tag)
{
	Tag = tag;
}

void Collider::Init()
{
	transform = &Entity->GetComponent<Transform>();

	if (Entity->HasComponent<SpriteRenderer>())
	{
		spriteRenderer = &Entity->GetComponent<SpriteRenderer>();
	}

	Collision::colliders.push_back(this);
}

void Collider::Update()
{
	collider.x = (int)transform->position.x;
	collider.y = (int)transform->position.y;

	if (spriteRenderer != nullptr)
	{
		collider.w = (int)(spriteRenderer->spriteSize.x * transform->scale.x);
		collider.h = (int)(spriteRenderer->spriteSize.y * transform->scale.y);
	}
	else
	{
		collider.w = 1;
		collider.h = 1;
	}
}
