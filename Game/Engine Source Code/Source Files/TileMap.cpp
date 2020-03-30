#include "TileMap.h"
#include "EngineCore.h"

#include <fstream>

TileMap::TileMap()
{	
}

TileMap::~TileMap()
{
}

void TileMap::LoadMap(std::string path, Vector2 size)
{
	char tile;
	std::fstream mapFile;
	mapFile.open(path);

	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			mapFile.get(tile);
			AddTile(atoi(&tile), Vector3(x * size.x, y * size.y, 0));
			mapFile.ignore();
		}
	}

	mapFile.close();
}

void TileMap::AddTile(int id, Vector3 position)
{
	auto& tile(EngineCore::Ecs->AddEntity());

	tile.AddComponent<Tile>(position, Vector2(32, 32), id);
}
