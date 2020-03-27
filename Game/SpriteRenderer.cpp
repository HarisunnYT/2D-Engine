#include "SpriteRenderer.h"
#include "TextureManager.h"
#include "Transform.h"

SpriteRenderer::SpriteRenderer(const char* path)
{
	SetTexture(path);
}

void SpriteRenderer::Init()
{
	transform = &Entity->AddComponent<Transform>();

	sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = 64;
	sourceRect.h = 64;

	destinationRect.w = 64;
	destinationRect.h = 64;
}

void SpriteRenderer::Update()
{
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
