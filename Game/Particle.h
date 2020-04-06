#pragma once

#ifndef PARTICLE_H
#define PARTICLE_H

#include "EngineCore.h"

enum 
{
	PARTICLE_LOOP,
	PARTICLE_HIDE,
	PARTICLE_DESTROY
};

class Particle : public SpriteRenderer
{
public:

	Particle(const char* path, Vector2 sheetSize, Vector2 frames, int speed, int endType);

	void Init() override;
	void Update() override;

	void OnEnable() override;

	void SetSpeed(int speed);

private:

	Vector2			frames;
	int				speed = 100;

	int				ticksOffset;
	int				endType;

	bool			initialPlay = true;
};

#endif