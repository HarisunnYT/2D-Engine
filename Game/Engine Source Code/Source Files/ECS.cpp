#include "ECS.h"
#include "Entity.h"
#include "Animator.h"

#include "PlayerController.h"

#include <fstream>
#include <iostream>

std::vector<Transform*> ECS::transforms;

void ECS::Update()
{
	for (auto& e : entities)
	{
		e->Update();
	}
}

struct compare_z_depth
{
	inline bool operator() (Transform *a, Transform *b)
	{
		return a->GetPosition().z < b->GetPosition().z;
	}
};


void ECS::Draw()
{
	sort(transforms.begin(), transforms.end(), compare_z_depth());
	for (auto& transform : transforms)
	{
		transform->entity->Draw();
	}
}

void ECS::Refresh()
{
	entities.erase(std::remove_if(std::begin(entities), std::end(entities), [](const std::unique_ptr<Entity>& mEntity)
	{
		return !mEntity->IsActive();
	}),
	std::end(entities));
}

void ECS::Physics()
{
	for (auto& e : entities)
	{
		e->Physics();
	}
}

void ECS::DebugDraw()
{
	if (EngineCore::isDebug)
	{
		for (auto& transform : transforms)
		{
			transform->entity->DebugDraw();
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
	std::unique_ptr<Entity> uPtr{ entity };
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

		return *entity;
	}

	throw std::invalid_argument("prefab does not exist");
}