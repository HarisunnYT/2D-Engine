#pragma once

#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "SpriteRenderer.h"

#include <map>

struct Animation
{
	int index;
	int frames;
	int speed;

	Animation() = default;
	Animation(int i, int f, int s)
	{
		index = i;
		frames = f;
		speed = s;
	}
};

class Animator : public SpriteRenderer
{
public:

	Animator(const char* path, Vector2 size);

	void Init() override;
	void Update() override;

	void AddNewAnimation(const char* animName, int index, int frames, int speed);
	void PlayAnimation(const char* animName);
	void PlayAnimation(int index);

	int animIndex = 0;
	std::map<const char*, Animation> animations;

private:

	int frames = 1;
	int speed = 100; //delay between frames in milliseconds
};

#endif