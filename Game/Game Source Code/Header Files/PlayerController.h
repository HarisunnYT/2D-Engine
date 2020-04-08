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
	void Update() override;

	void OnCollision(Hit* hit) override;
	void OnTrigger(Hit* hit) override;

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
	float jumpSpeed = 100.0f;
	float jumpLerpSpeed = 5.0f;

	float maxJumpVelocity = 225.0f;

	Transform* transform;
	Rigidbody* rigidbody;
	Animator* animator;
	Collider* collider;

};

#endif