#pragma once

#ifndef COMPONENT_H
#define COMPONENT_H

#include "Entity.h"

#include <string>

class Entity;
class Component
{
public:
	Entity* entity;

	virtual ~Component() {}

	virtual void Init() {}
	virtual void Update() {}
	virtual void Draw() {}
	virtual void Physics() {}
	virtual void DebugDraw() {}

	virtual std::string Parse() { return ""; }

};

#endif