#include "Entity.h"
#include "Component.h"

Entity::Entity()
{
	ECS::transforms.push_back(&AddComponent<Transform>());
}

void Entity::Update()
{
	for (auto& c : components)
	{
		c->Update();
	}
}

void Entity::Draw()
{
	for (auto& c : components)
	{
		c->Draw();
	}
}

void Entity::Destroy()
{
	active = false;
}

void Entity::Physics()
{
	for (auto& c : components)
	{
		c->Physics();
	}
}

void Entity::DebugDraw()
{
	for (auto& c : components)
	{
		c->DebugDraw();
	}
}

bool Entity::IsActive() const
{
	return active;
}
