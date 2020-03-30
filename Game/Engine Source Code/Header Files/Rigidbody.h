#pragma once

#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "EngineCore.h"

class Transform;
class Rigidbody : public Component
{
public:

	void Init() override;
	void Update() override;

	Vector3 Velocity;

private:

	Transform* transform;
};

#endif