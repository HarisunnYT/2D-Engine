#include "Collider.h"

std::string Collider::componentName = "collider";

vector<Collider*> Collision::colliders;

Collider::Collider(std::string tag)
{
	Tag = tag;

	offset = Vector2(0, 0);
	size = Vector2(1, 1);
}

void Collider::Init()
{
	transform = &entity->GetComponent<Transform>();
	if (entity->HasComponent<SpriteRenderer>())
	{
		spriteRenderer = &entity->GetComponent<SpriteRenderer>();
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

std::string Collider::Parse()
{
	std::stringstream ss;
	{
		cereal::JSONOutputArchive oarchive(ss);
		oarchive(Collider::componentName, Tag, offset.ToString(), size.ToString());
	}

	return ss.str();
}

bool Collider::TryParse(std::string value, Entity* entity)
{
	std::string name;
	std::string tag;
	std::string inOffset;
	std::string inSize;

	std::stringstream ss(value);
	{
		cereal::JSONInputArchive oarchive(ss);
		oarchive(name, tag, inOffset, inSize);
	}

	if (name == Collider::componentName)
	{
		entity->AddComponent<Collider>(tag);
		entity->GetComponent<Collider>().SetSize(Vector2::FromString(inSize));
		entity->GetComponent<Collider>().SetOffset(Vector2::FromString(inOffset));

		return true;
	}

	return false;
}

void Collider::UpdateCollider()
{
	collider.w = size.x * transform->scale.x;
	collider.h = size.y * transform->scale.y;

	collider.x = (int)transform->GetPosition().x + offset.x;
	collider.y = (int)transform->GetPosition().y + offset.y;
}
