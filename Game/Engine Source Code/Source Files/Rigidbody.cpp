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
	if (useGravity && !sleeping)
	{
		velocity.y += Physics::gravity.y * mass;
	}

	float threshold = abs(transform->GetRawPosition().y - lastPosition.y);

	if (!sleeping && threshold < sleepThreshold)
	{
		if (sleepTimer == 0)
		{
			sleepTimer = SDL_GetTicks() + timeTillSleep;
		}
		else if (SDL_GetTicks() >= sleepTimer)
		{
			sleeping = true;
		}
	}
	else if (threshold > sleepThreshold)
	{
		sleeping = false;
		sleepTimer = 0;
	}

	lastPosition = transform->GetRawPosition();
}

void Rigidbody::LateUpdate()
{
	transform->SetPosition((transform->GetPosition() + (Vector3(velocity.x, -velocity.y, 0) * EngineCore::fixedTimeStep)));
}

void Rigidbody::SetVelocity(Vector2 v)
{
	float mag = abs(v.x - velocity.x);
	if (mag > 0.0 || v.x != 0)
	{
		ForceAwake();
	}

	velocity = v;
}

Vector2 Rigidbody::GetVelocity()
{
	return velocity;
}

bool Rigidbody::IsSleeping()
{
	return sleeping;
}

void Rigidbody::ForceAwake()
{
	sleeping = false;
	sleepTimer = 0;
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


