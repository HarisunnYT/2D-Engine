#include "ECS.h"
#include "Entity.h"

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
		return a->position.z < b->position.z;
	}
};


void ECS::Draw()
{
	sort(transforms.begin(), transforms.end(), compare_z_depth());
	for (auto& transform : transforms)
	{
		transform->Entity->Draw();
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

Entity& ECS::AddEntity()
{
	Entity* e = new Entity();
	std::unique_ptr<Entity> uPtr{ e };
	entities.emplace_back(std::move(uPtr));

	return *e;
}