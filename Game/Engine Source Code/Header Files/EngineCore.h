#ifndef ENGINECORE_H
#define ENGINECORE_H

#include "SDL.h"
#include "SDL_image.h"
#include "Vector3.h"
#include "Vector2.h"
#include "Collision.h"
#include "Physics.h"
#include "Components.h"

#include <stdio.h>

class Camera;
class ECS;
class EngineCore
{
public:

	EngineCore();
	~EngineCore();

	void Init(const char* title, int xpos, int ypos, bool fullscreen);

	void HandleEvents();
	void Update(float dTime);
	void FixedUpdate();
	void Render();
	void Clean();

	bool Running();

	static SDL_Renderer*	Renderer;
	static SDL_Event		Event;
	static ECS*				Ecs;
	static Camera*			camera;

	static bool				isRunning;
	static bool				isDebug;

	static Vector2			screenSize;

	static float			deltaTime;
	static float			fixedTimeStep;

private:

	SDL_Window* window;
};

#endif