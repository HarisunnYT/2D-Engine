#include "PlayerController.h"
#include "InputSystem.h"

std::string PlayerController::componentName = "playercontroller";

PlayerController::PlayerController(float s)
{
	speed = s;
}

void PlayerController::Init()
{
	rigidbody = &entity->AddComponent<Rigidbody>();
	transform = &entity->GetComponent<Transform>();
	animator = &entity->GetComponent<Animator>();
	collider = &entity->GetComponent<Collider>();
}

void PlayerController::Update()
{
	Vector2 velocity = rigidbody->GetVelocity();
	if (InputSystem::KeyHeld(SDLK_a))
	{
		velocity.x = -1 * speed;
		animator->PlayAnimation("WalkLeft");
	}
	else if (InputSystem::KeyHeld(SDLK_d))
	{
		velocity.x = 1 * speed;
		animator->PlayAnimation("WalkRight");
	}
	else
	{
		velocity.x = 0;
	}

	if (InputSystem::KeyPressed(SDLK_SPACE))
	{
		velocity.y = 100;
	}

	rigidbody->SetVelocity(velocity);
}

std::string PlayerController::Parse()
{
	std::stringstream ss;
	{
		cereal::JSONOutputArchive oarchive(ss);
		oarchive(PlayerController::componentName, speed);
	}

	return ss.str();
}

bool PlayerController::TryParse(std::string value, Entity* entity)
{
	std::string name;
	float speed;

	std::stringstream ss(value);
	{
		cereal::JSONInputArchive oarchive(ss);
		oarchive(name, speed);
	}

	if (name == PlayerController::componentName)
	{
		entity->AddComponent<PlayerController>(speed);
		return true;
	}

	return false;
}
