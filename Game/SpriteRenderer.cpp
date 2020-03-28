#include "SpriteRenderer.h"
#include "TextureManager.h"
#include "Transform.h"

SpriteRenderer::SpriteRenderer(const char* p, Vector2 size)
{
	SpriteSize = Vector2((float)size.x, (float)size.y);
	currentPath = (char*)p;
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

	SetTexture(currentPath);
}

void SpriteRenderer::Update()
{
	destinationRect.w = static_cast<int>(SpriteSize.x * transform->Scale.x);
	destinationRect.h = static_cast<int>(SpriteSize.y * transform->Scale.y);

	destinationRect.x = static_cast<int>(transform->Position.x);
	destinationRect.y = static_cast<int>(transform->Position.y);
}

void SpriteRenderer::Draw()
{
	TextureManager::Draw(texture, sourceRect, destinationRect);
}

void SpriteRenderer::SetTexture(const char* path)
{
	texture = TextureManager::LoadTexture(path);
	currentPath = (char*)path;
}
