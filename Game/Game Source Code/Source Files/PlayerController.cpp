#include "PlayerController.h"
#include "InputSystem.h"

void PlayerController::Init()
{
	rigidbody = &Entity->AddComponent<Rigidbody>();
	transform = &Entity->AddComponent<Transform>();
	
	Entity->AddComponent<Collider>("player");

	animator = &Entity->AddComponent<Animator>("Assets/player_sprite_sheet.png", Vector2(64, 69));
	animator->AddNewAnimation("WalkUp", 0, 8, 150);
	animator->AddNewAnimation("WalkLeft", 1, 8, 150);
	animator->AddNewAnimation("WalkDown", 2, 8, 150);
	animator->AddNewAnimation("WalkRight", 3, 8, 150);
	animator->PlayAnimation(0);

	transform->scale = Vector2(2.0f, 2.0f);
}

void PlayerController::Update()
{
	if (InputSystem::KeyPressed(SDLK_w))
	{
		rigidbody->Velocity.y = -1;
		animator->PlayAnimation("WalkUp");
	}
	if (InputSystem::KeyPressed(SDLK_s))
	{
		rigidbody->Velocity.y = 1;
		animator->PlayAnimation("WalkDown");
	}
	if (InputSystem::KeyPressed(SDLK_a))
	{
		rigidbody->Velocity.x = -1;
		animator->PlayAnimation("WalkLeft");
	}
	if (InputSystem::KeyPressed(SDLK_d))
	{
		rigidbody->Velocity.x = 1;
		animator->PlayAnimation("WalkRight");
	}

	if (InputSystem::KeyReleased(SDLK_w) || InputSystem::KeyReleased(SDLK_s))
	{
		rigidbody->Velocity.y = 0;
	}
	if (InputSystem::KeyReleased(SDLK_a) || InputSystem::KeyReleased(SDLK_d))
	{
		rigidbody->Velocity.x = 0;
	}
}
