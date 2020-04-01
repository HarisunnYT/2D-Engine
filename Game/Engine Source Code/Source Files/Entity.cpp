#include "Entity.h"
#include "Component.h"

#include <iostream>
#include <fstream>

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

void Entity::SaveToDisk(const char* path)
{
	std::string data;
	for (auto& c : components)
	{
		std::string result = c->Parse();
		if (result != "")
		{
			data.append(result);
			data.append("\n");
			data.append("\n");
		}
	}

	std::ofstream file(path);
	file << data;
}
