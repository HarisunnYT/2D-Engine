#pragma once

#ifndef MAP_H
#define MAP_H

#include "Game.h"

class Map
{
public:

	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();

private:

	SDL_Rect		sourceRect;
	SDL_Rect		destinationRect;

	SDL_Texture*	dirt;
	SDL_Texture*	grass;
	SDL_Texture*	water;

	int				map[20][25];
};

#endif