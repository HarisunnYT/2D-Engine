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
	void FixedUpdate() override;

	void OnCollision(Hit* hit) override;
	void OnTrigger(Hit* hit) override;

	void SetBig(bool big);

	std::string Parse() override;
	static bool TryParse(std::string value, Entity* entity);
	static std::string componentName;

	template<class Archive>
	void Serialize(Archive& archive)
	{
		archive(componentName, speed);
	}

private:

	float		speed = 2.0f;
	float		jumpSpeed = 100.0f;
	float		jumpLerpSpeed = 5.0f;

	float		maxJumpVelocity = 225.0f;

	bool		jumping = false;
	bool		inAir = false;
	bool		isBig = false;

	bool		growing = false;
	float		growDuration = 0.5f;
	float		timer = 0;

	int			currentDirection = 0;

	Transform*	transform = nullptr;
	Rigidbody*	rigidbody = nullptr;
	Animator*	animator = nullptr;
	Collider*	collider = nullptr;

};

#endif