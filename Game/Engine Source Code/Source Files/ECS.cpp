#include "ECS.h"
#include "Entity.h"
#include "Animator.h"

#include "PlayerController.h"

#include <fstream>
#include <iostream>

ECS::ECS()
{
	entities = std::list<Entity*>();
}

void ECS::Update()
{
	for (auto& e : entities)
	{
		e->Update();
	}
}

struct compare_z_depth
{
	inline bool operator() (Entity *a, Entity *b)
	{
		return a->transform->GetPosition().z < b->transform->GetPosition().z;
	}
};


void ECS::Draw()
{
	entities.sort(compare_z_depth());
	for (auto& entity : entities)
	{
		if (entity != nullptr)
		{
			entity->Draw();
		}
	}
}

void ECS::Physics()
{
	for (auto& e : entities)
	{
		if (e != nullptr)
		{
			e->Physics();
		}
	}
}

void ECS::LateUpdate()
{
	for (auto& e : entities)
	{
		if (e != nullptr)
		{
			e->LateUpdate();
		}
	}
}

void ECS::FixedUpdate()
{
	for (auto& e : entities)
	{
		if (e != nullptr)
		{
			e->FixedUpdate();
		}
	}
}

void ECS::DebugDraw()
{
	if (EngineCore::isDebug)
	{
		for (auto& entity : entities)
		{
			if (entity != nullptr)
			{
				entity->DebugDraw();
			}
		}
	}
}

Entity& ECS::AddEntity()
{
	Entity* e = new Entity();
	return AddEntity(e);
}

Entity& ECS::AddEntity(Entity* entity)
{
	Entity* uPtr{ entity };
	entities.emplace_back(std::move(uPtr));

	return *entity;
}

Entity& ECS::AddEntity(const char* path)
{
	std::ifstream file(path);
	std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));

	vector<std::string> values;

	std::string currentVal;
	char previousCharacter = ' ';

	for (auto& c : content)
	{
		if (c == '\n' && previousCharacter == '}')
		{
			values.push_back(currentVal);
			currentVal.clear();
		}
		else
		{
			currentVal.push_back(c);
		}

		previousCharacter = c;
	}

	if (values.size() > 0)
	{
		Entity* entity = &EngineCore::Ecs->AddEntity();
		for (auto& str : values)
		{
			if (str.find("transform") != string::npos && Transform::TryParse(str, entity)) {}
			else if (str.find("collider") != string::npos && Collider::TryParse(str, entity)) {}
			else if (str.find("spriterenderer") != string::npos && SpriteRenderer::TryParse(str, entity)) {}
			else if (str.find("rigidbody") != string::npos && Rigidbody::TryParse(str, entity)) {}
			else if (str.find("playercontroller") != string::npos && PlayerController::TryParse(str, entity)) {}
			else if (str.find("animator") != string::npos && Animator::TryParse(str, entity)) {}
			else if (str.find("tile") != string::npos && Tile::TryParse(str, entity)) {}
		}

		entities.emplace_back(std::move(entity));

		return *entity;
	}

	throw std::invalid_argument("prefab does not exist");
}