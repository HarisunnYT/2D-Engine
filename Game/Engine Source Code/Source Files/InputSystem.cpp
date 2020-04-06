#include "InputSystem.h"

SDL_Point InputSystem::MousePosition;

bool InputSystem::KeyHeld(Uint8 SDL_SCANCODE)
{
	return SDL_GetKeyboardState(NULL)[SDL_SCANCODE];
}

bool InputSystem::MousePressed()
{
	return EngineCore::Event.type == SDL_MOUSEBUTTONDOWN;
}

bool InputSystem::MouseReleased()
{
	return EngineCore::Event.type == SDL_MOUSEBUTTONUP;
}

void InputSystem::Update()
{
	SDL_GetMouseState(&MousePosition.x, &MousePosition.y);
}