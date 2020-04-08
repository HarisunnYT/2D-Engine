#include "Brick.h"
#include "Coin.h"

#include <time.h>

std::string Brick::componentName = "brick";

Entity* coin;

Brick::Brick(int type)
{
	brickType = type;
}

void Brick::Init()
{
	if (brickType == COINSPAWNER)
	{
		coin = &EngineCore::Ecs->AddEntity("Assets/Prefabs/coin");
		coin->SetActive(false);
	}
}

void Brick::FixedUpdate()
{
	if (bumping)
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
			normTime = normTime - 1.0f;

			if (normTime >= 1.0f)
			{
				bumping = false;
				return;
			}

			Vector3 l = Vector3::Lerp(toPosition, fromPosition, normTime);
			entity->transform->SetRawPosition(l);
		}
	}
}

void Brick::Bump()
{
	if (!bumping && canBump)
	{
		fromPosition = entity->transform->GetRawPosition();
		toPosition = entity->transform->GetRawPosition() + Vector3(0.0f, (float)bumpAmount, 0.0f);

		timer = 0.0f;
		bumping = true;

		if (brickType >= ITEMSPAWNER)
		{
			coin->transform->SetPosition(entity->transform->GetPosition() + Vector3(-12, -75, 0));
			coin->GetComponent<Coin>().Bump();
			coin->SetActive(true);

			entity->GetComponent<Tile>().SetSource(Vector2(96.0f, 32.0f));
			canBump = false;
		}
	}
}

std::string Brick::Parse()
{
	std::stringstream ss;
	{
		cereal::JSONOutputArchive oarchive(ss);
		oarchive(Brick::componentName);
	}

	return ss.str();
}

bool Brick::TryParse(std::string value, Entity* entity)
{
	int brickType;
	std::string name;

	std::stringstream ss(value);
	{
		cereal::JSONInputArchive oarchive(ss);
		oarchive(name, brickType);
	}

	if (name == Brick::componentName)
	{
		entity->AddComponent<Brick>(brickType);

		return true;
	}

	return false;
}