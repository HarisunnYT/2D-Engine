#include "SpriteRenderer.h"
#include "TextureManager.h"
#include "Transform.h"

SpriteRenderer::SpriteRenderer(const char* path, int width, int size)
{
	SetTexture(path);

	SpriteSize = Vector2((float)width, (float)size);
}

SpriteRenderer::~SpriteRenderer()
{
	SDL_DestroyTexture(texture);
}

void SpriteRenderer::Init()
{
	transform = &Entity->AddComponent<Transform>();

	sourceRect.x = 0;
	sourceRect.y = 0;

	sourceRect.w = (int)SpriteSize.x;
	sourceRect.h = (int)SpriteSize.y;

	destinationRect.w = (int)(SpriteSize.x * transform->Scale.x);
	destinationRect.h = (int)(SpriteSize.y * transform->Scale.y);
}

void SpriteRenderer::Update()
{
	destinationRect.w = (int)(SpriteSize.x * transform->Scale.x);
	destinationRect.h = (int)(SpriteSize.y * transform->Scale.y);

	destinationRect.x = (int)transform->Position.x;
	destinationRect.y = (int)transform->Position.y;
}

void SpriteRenderer::Draw()
{
	TextureManager::Draw(texture, sourceRect, destinationRect);
}

void SpriteRenderer::SetTexture(const char* path)
{
	texture = TextureManager::LoadTexture(path);
}
