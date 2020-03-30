#include "Tile.h"

Tile::Tile(const char* p, Vector3 pos, Vector2 size, Vector2 source, float s)
{
	texture = TextureManager::LoadTexture(p);
	position = pos;
	scale = s;

	sourceRect.x = static_cast<int>(source.x);
	sourceRect.y = static_cast<int>(source.y);
	sourceRect.w = static_cast<int>(size.x);
	sourceRect.h = static_cast<int>(size.y);

	destinationRect.x = static_cast<int>(pos.x);
	destinationRect.y = static_cast<int>(pos.y);
	destinationRect.w = static_cast<int>(size.x * s);
	destinationRect.h = static_cast<int>(size.y * s);
}

Tile::~Tile()
{
	SDL_DestroyTexture(texture);
}

void Tile::Update()
{
	destinationRect.x = position.x - EngineCore::Camera.x * scale;
	destinationRect.y = position.y - EngineCore::Camera.y * scale;
}

void Tile::Draw()
{
	TextureManager::Draw(texture, sourceRect, destinationRect);
}
