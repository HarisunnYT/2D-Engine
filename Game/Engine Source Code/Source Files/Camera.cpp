#include "..\Header Files\Camera.h"

Camera::Camera()
{
	transform = &AddComponent<Transform>(Vector3(EngineCore::screenSize.x, EngineCore::screenSize.y, 0));
}

void Camera::Update()
{
	offset = { 0, 0, static_cast<int>(transform->GetPosition().x), static_cast<int>(transform->GetPosition().y) };

	Entity::Update();
}
