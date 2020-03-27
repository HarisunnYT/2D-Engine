#include "ECS.h"
#include "Entity.h"

void ECS::Update()
{
	for (auto& e : entities)
	{
		e->Update();
	}
}

void ECS::Draw()
{
	for (auto& e : entities)
	{
		e->Draw();
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
