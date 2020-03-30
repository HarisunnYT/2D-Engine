#include "Transform.h"

Transform::Transform()
{
	scale = Vector2(1, 1);
}

Transform::Transform(Vector3 pos) : Transform()
{
	position = pos;
}
