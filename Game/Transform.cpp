#include "Transform.h"

Transform::Transform()
{
	Scale = Vector2(1, 1);
}

Transform::Transform(Vector3 &pos) : Transform()
{
	Position = pos;
}
