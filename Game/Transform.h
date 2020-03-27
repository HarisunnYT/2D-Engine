#pragma once

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "EngineCore.h"

class Transform : public Component
{
public:

	Transform() = default;
	Transform(Vector3 &pos);
	
	Vector3 Position;

};

#endif