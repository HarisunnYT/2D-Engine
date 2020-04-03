#include "..\Header Files\Camera.h"

Camera::Camera()
{
	transform = &AddComponent<Transform>(Vector3(EngineCore::screenSize.x, EngineCore::screenSize.y, 0));
	offset = { 0, 0, static_cast<int>(EngineCore::screenSize.x), static_cast<int>(EngineCore::screenSize.y) };
}

bool Camera::InsideCameraView(SDL_Rect* rect)
{
	inputTopLeft = Vector2(rect->x, rect->y);
	inputBottomLeft = Vector2(rect->x, rect->y + rect->h);

	inputTopRight = Vector2(rect->x + rect->w, rect->y);
	inputBottomRight = Vector2(rect->x + rect->w, rect->y + rect->h);

	if (inputTopRight.x >= screenTopLeft.x && inputTopLeft.x <= screenTopRight.x &&
		inputBottomLeft.y > screenTopLeft.y && inputTopRight.y < screenBottomRight.y)
	{
		return true;
	}

	return false;
}
