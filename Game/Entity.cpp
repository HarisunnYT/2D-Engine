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

bool Entity::IsActive() const
{
	return active;
}
