#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, Vector3* pos)
{
	objectTexture = TextureManager::LoadTexture(textureSheet);

	position = pos;
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	sourceRect.h = 64;
	sourceRect.w = 64;
	sourceRect.x = 0;
	sourceRect.y = 0;

	destinationRect.x = position->x;
	destinationRect.y = position->y;
	destinationRect.w = sourceRect.w * 2;
	destinationRect.h = sourceRect.h * 2;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::Renderer, objectTexture, &sourceRect, &destinationRect);
}
