#pragma once

#ifndef ECS_H
#define ECS_H

#include "Components.h"

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Entity;
class Transform;
class ECS
{
public:

	void Update();
	void Draw();
	void Refresh();
	void Physics();
	void DebugDraw();

	Entity& AddEntity();
	Entity& AddEntity(const char* path);

	static std::vector<Transform*> transforms;

	void TryParseComponent(Transform *transform);

private:

	std::vector<std::unique_ptr<Entity>> entities;
};

#endif