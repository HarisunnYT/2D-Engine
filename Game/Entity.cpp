#include "Entity.h"
#include "Component.h"

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
