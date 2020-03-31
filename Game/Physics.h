#pragma once

#ifndef PHYSICS_H
#define PHYSICS_H

#include "EngineCore.h"

class Physics
{
public:

	static Vector2 gravity;

};

Vector2 Physics::gravity = Vector2(0, -9.81f);

#endif