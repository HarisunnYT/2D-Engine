#include "Rigidbody.h"

void Rigidbody::Init()
{
	transform = &Entity->GetComponent<Transform>();
}

void Rigidbody::Update()
{
	transform->position += Velocity;
}
