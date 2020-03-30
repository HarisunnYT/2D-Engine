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

	Entity& AddEntity();

	static std::vector<Transform*> transforms;

private:

	std::vector<std::unique_ptr<Entity>> entities;
};

#endif