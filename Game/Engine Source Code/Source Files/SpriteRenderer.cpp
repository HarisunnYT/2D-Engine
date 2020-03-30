#include "SpriteRenderer.h"
#include "TextureManager.h"
#include "Transform.h"

SpriteRenderer::SpriteRenderer(const char* p, Vector2 size)
{
	spriteSize = Vector2((float)size.x, (float)size.y);
	currentPath = (char*)p;
}

SpriteRenderer::~SpriteRenderer()
{
	SDL_DestroyTexture(texture);
}

void SpriteRenderer::Init()
{
	transform = &Entity->GetComponent<Transform>();

	sourceRect.x = 0;
	sourceRect.y = 0;

	sourceRect.w = (int)spriteSize.x;
	sourceRect.h = (int)spriteSize.y;

	destinationRect.w = (int)(spriteSize.x * transform->scale.x);
	destinationRect.h = (int)(spriteSize.y * transform->scale.y);

	SetTexture(currentPath);
}

void SpriteRenderer::Update()
{
	destinationRect.x = static_cast<int>(transform->position.x - EngineCore::Camera.x);
	destinationRect.y = static_cast<int>(transform->position.y - EngineCore::Camera.y);

	destinationRect.w = static_cast<int>(spriteSize.x * transform->scale.x);
	destinationRect.h = static_cast<int>(spriteSize.y * transform->scale.y);
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
