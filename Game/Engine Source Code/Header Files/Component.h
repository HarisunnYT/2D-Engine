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
	virtual void LateUpdate() {}
	virtual void FixedUpdate() {}
	virtual void DebugDraw() {}

	virtual void OnEnable() {}
	virtual void OnDisable() {}

	virtual std::string Parse() { return ""; }

};

#endif