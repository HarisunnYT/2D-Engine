#include "Tile.h"

Tile::Tile(const char* p, Vector3 position, Vector2 size, Vector2 source, float scale)
{
	texture = TextureManager::LoadTexture(p);

	sourceRect.x = static_cast<int>(source.x);
	sourceRect.y = static_cast<int>(source.y);
	sourceRect.w = static_cast<int>(size.x);
	sourceRect.h = static_cast<int>(size.y);

	destinationRect.x = static_cast<int>(position.x);
	destinationRect.y = static_cast<int>(position.y);
	destinationRect.w = static_cast<int>(size.x * scale);
	destinationRect.h = static_cast<int>(size.y * scale);
}

Tile::~Tile()
{
	SDL_DestroyTexture(texture);
}

void Tile::Draw()
{
	TextureManager::Draw(texture, sourceRect, destinationRect);
}
