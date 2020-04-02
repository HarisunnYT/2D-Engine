#include "..\Header Files\Camera.h"

Camera::Camera()
{
	transform = &AddComponent<Transform>(Vector3(EngineCore::screenSize.x, EngineCore::screenSize.y, 0));
	offset = { 0, 0, static_cast<int>(EngineCore::screenSize.x), static_cast<int>(EngineCore::screenSize.y) };
}
