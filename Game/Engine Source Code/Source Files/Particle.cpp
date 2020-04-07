#include "Particle.h"

Particle::Particle(const char* path, Vector2 sheetSize, Vector2 f, int s, int eType) : SpriteRenderer(path, sheetSize)
{
	frames = f;
	speed = s;

	endType = eType;
}

void Particle::Init()
{
	SpriteRenderer::Init();

	ticksOffset = SDL_GetTicks();
}

void Particle::Update()
{
	SpriteRenderer::Update();

	int totalOffset = static_cast<int>((SDL_GetTicks() - ticksOffset) / speed) % static_cast<int>(frames.x * frames.y);
	int xOffset = static_cast<int>((SDL_GetTicks() - ticksOffset) / speed) % static_cast<int>(frames.x);
	int yOffset = floor(totalOffset / frames.x);

	if (yOffset == 0 && !initialPlay && endType != PARTICLE_LOOP)
	{
		switch (endType)
		{
		case PARTICLE_DESTROY:
			entity->Destroy();
			break;
		case PARTICLE_HIDE:
			entity->SetActive(false);
			break;
		}

		return;
	}
	else if (yOffset > 0)
	{
		initialPlay = false;
	}

	sourceRect.x = sourceRect.w * xOffset;
	sourceRect.y = yOffset * static_cast<int>(spriteSize.y);
}

void Particle::OnEnable()
{
	ticksOffset = SDL_GetTicks();
	initialPlay = true;
}

void Particle::SetSpeed(int s)
{
	speed = s;
}
