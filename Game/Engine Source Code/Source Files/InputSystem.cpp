#include "InputSystem.h"

bool InputSystem::KeyPressed(int SDL_CODE)
{
	if (EngineCore::Event.type == SDL_KEYDOWN)
	{
		return EngineCore::Event.key.keysym.sym == SDL_CODE;
	}

	return false;
}

bool InputSystem::KeyReleased(int SDL_CODE)
{
	if (EngineCore::Event.type == SDL_KEYUP)
	{
		return EngineCore::Event.key.keysym.sym == SDL_CODE;
	}

	return false;
}
