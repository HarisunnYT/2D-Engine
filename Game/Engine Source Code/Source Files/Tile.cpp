#include "Tile.h"

vector<char*> Tile::tileTypes;

Tile::Tile(Vector3 position, Vector2 size, int id)
{
	tileRect.x = static_cast<int>(position.x);
	tileRect.y = static_cast<int>(position.y);
	tileRect.w = static_cast<int>(size.x);
	tileRect.h = static_cast<int>(size.y);
	tileID = id;
}

void Tile::Init()
{
	path = GetPath(tileID);

	transform = &Entity->GetComponent<Transform>();
	transform->position = Vector3(static_cast<float>(tileRect.x), static_cast<float>(tileRect.y), 0);

	spriteRenderer = &Entity->AddComponent<SpriteRenderer>(path, Vector2(64, 64));
}

void Tile::AddTileTexture(const char* path)
{
	Tile::tileTypes.push_back((char*)path);
}

char* Tile::GetPath(int id)
{
	if ((int)tileTypes.size() > id)
	{
		return tileTypes[id];
	}
	else
	{
		throw std::invalid_argument("path does not exist");
	}
}
