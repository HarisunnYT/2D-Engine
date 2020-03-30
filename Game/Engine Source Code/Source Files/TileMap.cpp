#include "TileMap.h"
#include "EngineCore.h"

#include <fstream>

TileMap::TileMap()
{	
}

TileMap::~TileMap()
{
}

void TileMap::LoadMap(std::string mapPath, const char* spriteSheetPath, Vector2 tileSize, Vector2 mapSize, float scale)
{
	char c;
	std::fstream mapFile;
	mapFile.open(mapPath);

	int sourceX, sourceY;

	for (int y = 0; y < mapSize.y; y++)
	{
		for (int x = 0; x < mapSize.x; x++)
		{
			mapFile.get(c);
			sourceY = static_cast<int>(atoi(&c) * tileSize.y);

			mapFile.get(c);
			sourceX = static_cast<int>(atoi(&c) * tileSize.x);

			AddTile(spriteSheetPath, Vector3(x * tileSize.x * scale, y * tileSize.y * scale, 0), tileSize, Vector2(static_cast<float>(sourceX), static_cast<float>(sourceY)), scale);
			mapFile.ignore();
		}
	}

	mapFile.close();
}

void TileMap::AddTile(const char* spriteSheetPath, Vector3 position, Vector2 size, Vector2 source, float scale)
{
	auto& tile(EngineCore::Ecs->AddEntity());

	tile.AddComponent<Tile>(spriteSheetPath, position, size, source, scale);
}
