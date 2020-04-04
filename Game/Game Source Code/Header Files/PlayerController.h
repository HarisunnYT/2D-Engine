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

	PlayerController(float speed = 1);

	void Init() override;
	void LateUpdate() override;

	std::string Parse() override;
	static bool TryParse(std::string value, Entity* entity);
	static std::string componentName;

	template<class Archive>
	void Serialize(Archive& archive)
	{
		archive(componentName, speed);
	}

private:

	float speed = 2.0f;

	Transform* transform;
	Rigidbody* rigidbody;
	Animator* animator;
	Collider* collider;

};

#endif