#include "Tile.h"

Tile::Tile(const char* p, Vector3 pos, Vector2 mSize, Vector2 source, float s)
{
	startingPosition = pos;
	size = mSize;
	startingScale = Vector2(s, s);

	texture = TextureManager::LoadTexture(p);

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

void Tile::Init()
{
	transform = &Entity->GetComponent<Transform>();
	transform->SetPosition(&startingPosition);
	transform->scale = startingScale;

	collider = &Entity->AddComponent<Collider>("tile");
	collider->SetSize(Vector2(sourceRect.w, sourceRect.h));
}

void Tile::Update()
{
	destinationRect.x = transform->GetPosition().x - EngineCore::Camera.x * transform->scale.x;
	destinationRect.y = transform->GetPosition().y - EngineCore::Camera.y * transform->scale.y;

	destinationRect.w = static_cast<int>(size.x * transform->scale.x);
	destinationRect.h = static_cast<int>(size.y * transform->scale.y);
}

void Tile::Draw()
{
	TextureManager::Draw(texture, sourceRect, destinationRect);
}
