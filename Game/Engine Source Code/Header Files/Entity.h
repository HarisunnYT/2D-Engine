#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <iostream>
#include <bitset>
#include <array>
#include "ECS.h"

class Component;

using ComponentID = std::size_t;

inline ComponentID GetComponentTypeID()
{
	static ComponentID lastID = 0;
	return lastID++;
}

template <typename T> inline ComponentID GetComponentTypeID() noexcept
{
	static ComponentID typeID = GetComponentTypeID();
	return typeID;
}

constexpr std::size_t MaxComponents = 32;

using ComponentBitSet = std::bitset<MaxComponents>;
using ComponentArray = std::array<Component*, MaxComponents>;

class Entity
{
public:

	Entity();

	void Update();
	void Draw();
	void Destroy();

	bool IsActive() const;

	template <typename T> bool HasComponent() const
	{
		return componentBitSet[GetComponentTypeID<T>()];
	}

	template <typename T, typename... TArgs> T& AddComponent(TArgs&&... mArgs)
	{
		if (!HasComponent<T>())
		{
			T* c(new T(std::forward<TArgs>(mArgs)...));
			c->Entity = this;
			std::unique_ptr<Component> uPtr{ c };
			components.emplace_back(std::move(uPtr));

			componentArray[GetComponentTypeID<T>()] = c;
			componentBitSet[GetComponentTypeID<T>()] = true;

			c->Init();
			return *c;
		}
		else
		{
			return GetComponent<T>();
		}
	}

	template <typename T> T& GetComponent() const
	{
		auto ptr(componentArray[GetComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}

private:

	bool active = true;

	std::vector<std::unique_ptr<Component>> components;

	ComponentArray		componentArray;
	ComponentBitSet		componentBitSet;
};

#endif