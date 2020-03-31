#include "PlayerController.h"
#include "InputSystem.h"

void PlayerController::Init()
{
	rigidbody = &Entity->AddComponent<Rigidbody>();
	transform = &Entity->AddComponent<Transform>();

	animator = &Entity->AddComponent<Animator>("Assets/player_sprite_sheet.png", Vector2(64, 69));
	animator->AddNewAnimation("WalkUp", 0, 8, 150);
	animator->AddNewAnimation("WalkLeft", 1, 8, 150);
	animator->AddNewAnimation("WalkDown", 2, 8, 150);
	animator->AddNewAnimation("WalkRight", 3, 8, 150);
	animator->PlayAnimation(0);

	transform->scale = Vector2(2.0f, 2.0f);
	transform->SetPosition(&Vector3(EngineCore::screenSize.x / 2, EngineCore::screenSize.y / 2, 1));

	collider = &Entity->AddComponent<Collider>("player");
	collider->SetSize(Vector2(30, 50));
	collider->SetOffset(Vector2(30, 20));
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
		velocity.y = 10;
	}

	rigidbody->SetVelocity(velocity);
}
