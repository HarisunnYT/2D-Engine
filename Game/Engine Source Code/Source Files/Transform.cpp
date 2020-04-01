#include "Transform.h"


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
		oarchive(position.ToString(), scale.ToString());
	}

	return ss.str();
}