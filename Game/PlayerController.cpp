#include "PlayerController.h"
#include "InputSystem.h"

void PlayerController::Init()
{
	rigidbody = &Entity->AddComponent<Rigidbody>();
	transform = &Entity->AddComponent<Transform>();
}

void PlayerController::Update()
{
	if (InputSystem::KeyPressed(SDLK_w))
	{
		rigidbody->Velocity.y = -1;
	}
	if (InputSystem::KeyPressed(SDLK_s))
	{
		rigidbody->Velocity.y = 1;
	}
	if (InputSystem::KeyPressed(SDLK_a))
	{
		rigidbody->Velocity.x = -1;
	}
	if (InputSystem::KeyPressed(SDLK_d))
	{
		rigidbody->Velocity.x = 1;
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
