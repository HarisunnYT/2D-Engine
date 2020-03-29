#pragma once

#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "Components.h"
#include "Game.h"
#include "ECS.h"
#include "Animator.h"

class PlayerController : public Component
{
public:

	void Init() override;
	void Update() override;

private:

	float speed = 2.0f;

	Transform* transform;
	Rigidbody* rigidbody;
	Animator* animator;

};

#endif