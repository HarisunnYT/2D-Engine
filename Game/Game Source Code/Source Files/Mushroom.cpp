#include "Mushroom.h"

std::string Mushroom::componentName = "mushroom";

void Mushroom::Spawn()
{
	fromPosition = entity->transform->GetRawPosition();
	toPosition = entity->transform->GetRawPosition() + Vector3(0.0f, (float)bumpAmount, 0.0f);

	timer = 0;
	spawning = true;
}

void Mushroom::FixedUpdate()
{
	if (spawning)
	{
		timer = timer + (EngineCore::fixedTimeStep / 2.0f);
		float normTime = timer / bumpDuration;

		if (normTime < 1.0f)
		{
			Vector3 l = Vector3::Lerp(fromPosition, toPosition, normTime);
			entity->transform->SetRawPosition(l);
		}
		else
		{
			spawning = false;
		}
	}
}

std::string Mushroom::Parse()
{
	std::stringstream ss;
	{
		cereal::JSONOutputArchive oarchive(ss);
		oarchive(Mushroom::componentName);
	}

	return ss.str();
}

bool Mushroom::TryParse(std::string value, Entity* entity)
{
	std::string name;

	std::stringstream ss(value);
	{
		cereal::JSONInputArchive oarchive(ss);
		oarchive(name);
	}

	if (name == Mushroom::componentName)
	{
		entity->AddComponent<Mushroom>();

		return true;
	}

	return false;
}