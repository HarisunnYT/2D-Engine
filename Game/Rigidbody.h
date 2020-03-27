#pragma once

#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Components.h"
#include "Vector3.h"

class Transform;
class Rigidbody : public Component
{
public:

	Rigidbody();

	Vector3 Velocity;

private:

	Transform* transform;

};

#endif