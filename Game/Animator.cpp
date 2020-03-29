#include "Animator.h"

Animator::Animator(const char* path, Vector2 size, int mFrames, int mSpeed) : SpriteRenderer(path, size)
{
	frames = mFrames;
	speed = mSpeed;
}

void Animator::Update()
{
	sourceRect.x = sourceRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);

	SpriteRenderer::Update();
}
