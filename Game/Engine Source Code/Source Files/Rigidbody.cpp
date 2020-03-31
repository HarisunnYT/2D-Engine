#include "Rigidbody.h"

Rigidbody::Rigidbody(bool gravity)
{
	useGravity = gravity;
}

void Rigidbody::Init()
{
	transform = &Entity->GetComponent<Transform>();
}

void Rigidbody::Physics()
{
	transform->SetPosition(&(transform->GetPosition() + Vector3(velocity.x, velocity.y, 0)));
}

void Rigidbody::SetVelocity(Vector2 v)
{
	velocity = v;
}

Vector2 Rigidbody::GetVelocity()
{
	return velocity;
}


