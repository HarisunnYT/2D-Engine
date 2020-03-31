#include "Collider.h"

vector<Collider*> Collision::colliders;

Collider::Collider(std::string tag)
{
	Tag = tag;

	offset = Vector2(0, 0);
	size = Vector2(1, 1);
}

void Collider::Init()
{
	transform = &Entity->GetComponent<Transform>();
	if (Entity->HasComponent<SpriteRenderer>())
	{
		spriteRenderer = &Entity->GetComponent<SpriteRenderer>();
	}

	if (spriteRenderer != nullptr)
	{
		size.x = (int)(spriteRenderer->spriteSize.x);
		size.y = (int)(spriteRenderer->spriteSize.y);
	}

	UpdateCollider();

	Collision::colliders.push_back(this);
}

void Collider::Update()
{
	UpdateCollider();
}

void Collider::DebugDraw()
{
	SDL_SetRenderDrawColor(EngineCore::Renderer, 0, 255, 0, 255);
	SDL_RenderDrawRect(EngineCore::Renderer, &collider);
	SDL_SetRenderDrawColor(EngineCore::Renderer, 255, 255, 255, 255);
}

void Collider::SetSize(Vector2 s)
{
	size = s;
	UpdateCollider();
}

void Collider::SetOffset(Vector2 o)
{
	offset = o;
}

const SDL_Rect Collider::GetCollider()
{
	UpdateCollider();

	return collider;
}

void Collider::UpdateCollider()
{
	collider.w = size.x * transform->scale.x;
	collider.h = size.y * transform->scale.y;

	collider.x = (int)transform->GetPosition().x + offset.x;
	collider.y = (int)transform->GetPosition().y + offset.y;
}
