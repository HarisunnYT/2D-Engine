#include "ECS.h"
#include "Entity.h"
#include "Animator.h"

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
	std::unique_ptr<Entity> uPtr{ e };
	entities.emplace_back(std::move(uPtr));

	return *e;
}

Entity& ECS::AddEntity(const char* path)
{
	Entity* e = &AddEntity();

	std::ifstream source(path);

	source >> noskipws;

	char c;
	std::string function;

	while (source >> c)
	{
		if (c == '\n')
		{
			std::cout << function << std::endl;

			//TryParseComponent(function, e);

			function.clear();
		}

		function.push_back(c);
	}

	return *e;
}

void ECS::TryParseComponent(Transform* transform)
{
	//Vector3 pos = Vector3(5, 7, 2);
	//Vector2 scale = Vector2(6.9f, 4.5f);
	//std::stringstream ss;
	//{
	//	cereal::BinaryOutputArchive oarchive(ss);
	//	oarchive(pos.ToString(), scale.ToString());
	//}

	//std::string rPos;
	//std::string rScale;
	//std::stringstream inStream(ss.str());
	//{
	//	cereal::BinaryInputArchive iarchive(inStream);
	//	iarchive(rPos, rScale);
	//}

	//Vector2 s = Vector2::FromString(rScale);
	//std::cout << s << std::endl;

	//cereal::BinaryInputArchive iarchive(ss);

	//Vector3 pos;

	//iarchive(pos.x, pos.y, pos.z);

	//std::cout << r << std::endl;

	//std::cout << pos.x << " " << pos.y << std::endl;

	//if (function.find("transform") != string::npos)
	//	Transform::TryParse(function, entity);
	//if (function.find("spriterenderer") != string::npos)
	//	//SpriteRenderer::TryParse(function, entity);
	//if (function.find("animator") != string::npos)
	//	//Animator::TryParse(function, entity);
	//if (function.find("collider") != string::npos)
	//	//Collider::TryParse(function, entity);
	//	if (function.find("rigidbody") != string::npos)
	//	{

	//}
		//Rigidbody::TryParse(function, entity);
}