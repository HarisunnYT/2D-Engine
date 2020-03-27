#pragma once

#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include "EngineCore.h"
#include "ECS.h"
#include "Components.h"

class InputSystem
{
public:

	static bool KeyHeld(int SDL_CODE);
	static bool KeyPressed(int SDL_CODE);
	static bool KeyReleased(int SDL_CODE);

};

#endif