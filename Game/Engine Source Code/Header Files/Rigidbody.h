#pragma once

#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "EngineCore.h"

class Transform;
class Rigidbody : public Component
{
public:

	Rigidbody() = default;
	Rigidbody(bool useGravity);

	void Init() override;
	void Update() override;
	void Physics() override;

	void SetVelocity(Vector2 velocity);
	Vector2 GetVelocity();

	float mass = 1;

private:

	Transform*		transform = nullptr;
	Vector2			velocity;

	bool			useGravity = true;
};

#endif