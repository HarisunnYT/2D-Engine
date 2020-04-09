#include "Goomba.h"
#include "Animator.h"

std::string Goomba::componentName = "goomba";

void Goomba::Init()
{
	rigidbody = &entity->GetComponent<Rigidbody>();
}

void Goomba::FixedUpdate()
{
	if (!dead)
	{
		rigidbody->SetVelocity(Vector2(direction * speed, rigidbody->GetVelocity().y));
	}
	else
	{
		timer = timer + (EngineCore::fixedTimeStep / 2.0f);
		float normTime = timer / deathDuration;

		if (normTime >= 1.0f)
		{
			entity->SetActive(false);
		}
	}
}

void Goomba::OnCollision(Hit* hit)
{
	if (hit->collider->Tag == "player")
	{
		if (hit->normal.y < -0.8f)
		{
			dead = true;

			rigidbody->SetVelocity(Vector2(0, 0));
			rigidbody->useGravity = false;

			entity->GetComponent<Collider>().Trigger = true;
			entity->GetComponent<Animator>().PlayAnimation(1);

			Vector3 pos = entity->transform->GetPosition();
			entity->transform->SetPosition(Vector3(pos.x, pos.y + 10, pos.z));

			Vector2 playerVel = hit->collider->entity->GetComponent<Rigidbody>().GetVelocity();
			hit->collider->entity->GetComponent<Rigidbody>().SetVelocity(Vector2(playerVel.x, 100));
		}
	}
	else if (abs(hit->normal.x) > 0.8f)
	{
		direction *= -1;
	}
}

std::string Goomba::Parse()
{
	std::stringstream ss;
	{
		cereal::JSONOutputArchive oarchive(ss);
		oarchive(Goomba::componentName);
	}

	return ss.str();
}

bool Goomba::TryParse(std::string value, Entity* entity)
{
	int brickType;
	std::string name;

	std::stringstream ss(value);
	{
		cereal::JSONInputArchive oarchive(ss);
		oarchive(name);
	}

	if (name == Goomba::componentName)
	{
		entity->AddComponent<Goomba>();

		return true;
	}

	return false;
}