#include "PlayerController.h"

void PlayerController::Init()
{
	transform = &Entity->GetComponent<Transform>();
	rigidbody = &Entity->GetComponent<Rigidbody>();
}

void PlayerController::Update()
{
	transform->Position += rigidbody->Velocity * speed;
}
