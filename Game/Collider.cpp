#include "Collider.h"

Collider::Collider(std::string tag)
{
	Tag = tag;
}

void Collider::Init()
{
	transform = &Entity->AddComponent<Transform>();

	if (Entity->HasComponent<SpriteRenderer>())
	{
		spriteRenderer = &Entity->GetComponent<SpriteRenderer>();
	}
}

void Collider::Update()
{
	collider.x = (int)transform->Position.x;
	collider.y = (int)transform->Position.y;

	if (spriteRenderer != nullptr)
	{
		collider.w = (int)(spriteRenderer->SpriteSize.x * transform->Scale.x);
		collider.h = (int)(spriteRenderer->SpriteSize.y * transform->Scale.y);
	}
	else
	{
		collider.w = 1;
		collider.h = 1;
	}
}
