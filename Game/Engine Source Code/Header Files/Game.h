#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>

class Game
{
public:

	Game();
	~Game();

	void Update();
	void Render();
};

#endif