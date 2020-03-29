#pragma once

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "EngineCore.h"

class Transform : public Component
{
public:

	Transform();
	Transform(Vector3 pos);
	
	Vector3 position;
	Vector2 scale;

};

#endif