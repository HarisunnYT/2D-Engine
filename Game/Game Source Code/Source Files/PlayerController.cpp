#include "PlayerController.h"
#include "InputSystem.h"
#include "Brick.h"

std::string PlayerController::componentName = "playercontroller";

bool jumping = false;

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
		velocity.y += jumpSpeed;
		jumping = true;
	}
	else if (!InputSystem::KeyHeld(SDL_SCANCODE_SPACE) || velocity.y >= maxJumpVelocity)
	{
		jumping = false;
	}

	if (jumping && InputSystem::KeyHeld(SDL_SCANCODE_SPACE) && velocity.y < maxJumpVelocity)
	{
		velocity.y += jumpLerpSpeed;
	}

	rigidbody->SetVelocity(velocity);
}

void PlayerController::OnCollision(Hit* hit)
{
	if (hit->normal.y < -0.95f)
	{
		if (hit->collider->Tag == "brick")
		{
			hit->collider->entity->GetComponent<Brick>().Bump();
		}

		jumping = false;
	}
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
