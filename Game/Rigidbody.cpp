#include "Rigidbody.h"

void Rigidbody::Init()
{
	transform = &Entity->AddComponent<Transform>();
}

void Rigidbody::Update()
{
	transform->Position += Velocity;
}
