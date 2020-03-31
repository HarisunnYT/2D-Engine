#pragma once

#ifndef COMPONENT_H
#define COMPONENT_H

#include "Entity.h"

class Entity;
class Component
{
public:
	Entity* Entity;

	virtual ~Component() {}

	virtual void Init() {}
	virtual void Update() {}
	virtual void Draw() {}
	virtual void Physics() {}
	virtual void DebugDraw() {}

};

#endif