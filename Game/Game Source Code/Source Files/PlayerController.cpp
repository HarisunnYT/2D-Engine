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
	if (InputSystem::KeyHeld(SDL_SCANCODE_A))
	{
		velocity.x = -1 * speed;
		animator->PlayAnimation("WalkLeft");
	}
	else if (InputSystem::KeyHeld(SDL_SCANCODE_D))
	{
		velocity.x = 1 * speed;
		animator->PlayAnimation("WalkRight");
	}
	else
	{
		velocity.x = 0;
	}

	if (InputSystem::KeyHeld(SDL_SCANCODE_SPACE) && velocity.y == 0)
	{
		velocity.y = 150;
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
