#include "Rigidbody.h"

std::string Rigidbody::componentName = "rigidbody";

Rigidbody::Rigidbody(bool gravity)
{
	useGravity = gravity;
}

void Rigidbody::Init()
{
	transform = &entity->GetComponent<Transform>();
}

void Rigidbody::Update()
{
	velocity.y += Physics::gravity.y * mass;
}

void Rigidbody::Physics()
{
	transform->SetPosition(&(transform->GetPosition() + Vector3(velocity.x, -velocity.y, 0)));
}

void Rigidbody::SetVelocity(Vector2 v)
{
	velocity = v;
}

Vector2 Rigidbody::GetVelocity()
{
	return velocity;
}

std::string Rigidbody::Parse()
{
	std::stringstream ss;
	{
		cereal::JSONOutputArchive oarchive(ss);
		oarchive(Rigidbody::componentName, mass, useGravity);
	}

	return ss.str();
}

bool Rigidbody::TryParse(std::string value, Entity* entity)
{
	std::string name;
	float inMass;
	bool inUseGravity;

	std::stringstream ss(value);
	{
		cereal::JSONInputArchive oarchive(ss);
		oarchive(name, inMass, inUseGravity);
	}

	if (name == Rigidbody::componentName)
	{
		entity->AddComponent<Rigidbody>(inUseGravity);
		entity->GetComponent<Rigidbody>().mass = inMass;

		return true;
	}

	return false;
}


