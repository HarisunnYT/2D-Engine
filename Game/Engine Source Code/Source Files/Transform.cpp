#include "Transform.h"

std::string Transform::componentName = "transform";

Transform::Transform()
{
	scale = Vector2(1, 1);
}

Transform::Transform(Vector3 pos) : Transform()
{
	position = pos;
}

Vector3 Transform::GetPosition()
{
	return position;
}

void Transform::SetPosition(Vector3 *pos)
{
	position = Vector3(pos->x - EngineCore::Camera.x, pos->y - EngineCore::Camera.y, pos->z);
}

std::string Transform::Parse()
{
	std::stringstream ss;
	{
		cereal::JSONOutputArchive oarchive(ss);
		oarchive(Transform::componentName, position.ToString(), scale.ToString());
	}

	return ss.str();
}

bool Transform::TryParse(std::string value, Entity* entity)
{
	std::string name;
	std::string inPos;
	std::string inScale;

	std::stringstream ss(value);
	{
		cereal::JSONInputArchive oarchive(ss);
		oarchive(name, inPos, inScale);
	}

	if (name == Transform::componentName)
	{
		entity->GetComponent<Transform>().SetPosition(&Vector3::FromString(inPos));
		entity->GetComponent<Transform>().scale = Vector2::FromString(inScale);

		return true;
	}

	return false;
}
