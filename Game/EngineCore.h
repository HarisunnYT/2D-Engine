#ifndef ENGINECORE_H
#define ENGINECORE_H

#include "SDL.h"
#include "SDL_image.h"
#include "Vector3.h"

#include "Components.h"

#include <stdio.h>

class ECS;
class EngineCore
{
public:

	EngineCore();
	~EngineCore();

	void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void HandleEvents();
	void Update();
	void Render();
	void Clean();

	bool Running();

	static SDL_Renderer* Renderer;
	static SDL_Event Event;
	static ECS* Ecs;

private:

	bool isRunning;
	SDL_Window* window;
};

#endif