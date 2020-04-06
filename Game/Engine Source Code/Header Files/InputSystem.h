#pragma once

#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include "EngineCore.h"
#include "ECS.h"
#include "Components.h"

class InputSystem
{
public:

	static bool KeyHeld(Uint8 SDL_SCANCODE);

	static bool MousePressed();
	static bool MouseReleased();

	static void Update();

	static SDL_Point MousePosition;

};

#endif