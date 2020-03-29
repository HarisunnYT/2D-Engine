#pragma once

#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "SpriteRenderer.h"

class Animator : public SpriteRenderer
{
public:

	Animator(const char* path, Vector2 size, int frames, int speed);

	void Update() override;

private:

	int frames;
	int speed = 100; //delay between frames in milliseconds
};

#endif