#include "PlayerController.h"
#include "InputSystem.h"
#include "Brick.h"

std::string PlayerController::componentName = "playercontroller";

bool jumping = false;
bool inAir = false;

int currentDirection = 0;

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

		if (inAir)
			animator->PlayAnimation("JumpLeft");
		else
			animator->PlayAnimation("WalkLeft");

		currentDirection = -1;
	}
	else if (InputSystem::KeyHeld(SDL_SCANCODE_D))
	{
		velocity.x = 1 * speed;
		
		if (inAir)
			animator->PlayAnimation("JumpRight");
		else
			animator->PlayAnimation("WalkRight");

		currentDirection = 1;
	}
	else
	{
		velocity.x = 0;
	}

	if (InputSystem::KeyHeld(SDL_SCANCODE_SPACE) && velocity.y == 0)
	{
		velocity.y += jumpSpeed;
		jumping = true;
		inAir = true;

		animator->PlayAnimation(currentDirection > 0 ? "JumpRight" : "JumpLeft");
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
	if (hit->normal.y < -0.8f)
	{
		if (hit->collider->Tag == "brick")
		{
			hit->collider->entity->GetComponent<Brick>().Bump();
		}

		jumping = false;
	}
	else if (hit->normal.y > 0.8f && !jumping)
	{
		inAir = false;
		animator->PlayAnimation(currentDirection > 0 ? "WalkRight" : "WalkLeft");
	}
}

void PlayerController::OnTrigger(Hit* hit)
{
	if (hit->collider->Tag == "invisibleBrick" && hit->normal.y < -0.8f && rigidbody->GetVelocity().y > 0)
	{
		hit->collider->entity->GetComponent<Collider>().Trigger = false;
		hit->collider->entity->GetComponent<Tile>().SetSource(Vector2(96.0f, 32.0f));
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
