#include "TileMap.h"
#include "EngineCore.h"

#include <fstream>

TileMap::TileMap()
{	
}

TileMap::~TileMap()
{
}

void TileMap::LoadMap(std::string mapPath, const char* spriteSheetPath, Vector2 tileSize, Vector2 mpSize, float scale)
{
	char c;
	std::fstream mapFile;
	mapFile.open(mapPath);

	int sourceX, sourceY;

	for (int y = 0; y < mpSize.y; y++)
	{
		for (int x = 0; x < mpSize.x; x++)
		{
			std::string id;
			mapFile.get(c);
			sourceY = static_cast<int>(atoi(&c) * tileSize.y);

			id.push_back(c);

			mapFile.get(c);
			sourceX = static_cast<int>(atoi(&c) * tileSize.x);

			id.push_back(c);

			AddTile(spriteSheetPath, id, Vector3(x * tileSize.x * scale, y * tileSize.y * scale, 0), tileSize, Vector2(static_cast<float>(sourceX), static_cast<float>(sourceY)), scale);
			mapFile.ignore();
		}
	}

	mapFile.close();

	mapSize = mpSize * scale;
}

void TileMap::AddTile(const char* spriteSheetPath, std::string id, Vector3 position, Vector2 size, Vector2 source, float scale)
{
	std::string p = "Assets/Prefabs/Tiles/" + id;
	std::ifstream inFile(p);

	if (inFile.good())
	{
		auto& tile (EngineCore::Ecs->AddEntity(p.c_str()));
		tile.GetComponent<Tile>().ManualConstruction(position, scale);
		tile.GetComponent<Tile>().Init();
	}
	else
	{
		auto& tile(EngineCore::Ecs->AddEntity());
		tile.AddComponent<Tile>(spriteSheetPath, position, size, source, scale);
	}
}
