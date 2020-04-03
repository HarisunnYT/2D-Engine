#include "Collision.h"
#include "Collider.h"

int gridSize = 200;

vector<pair<SDL_Rect, vector<Collider*>>> Collision::grid;

void Collision::Init()
{
	int cols = static_cast<int>(EngineCore::screenSize.x / gridSize);
	int rows = static_cast<int>(EngineCore::screenSize.y / gridSize);

	for (int x = 0; x < cols; x++)
	{
		for (int y = 0; y < rows; y++)
		{
			SDL_Rect rect;

			rect.x = x * gridSize;
			rect.y = y * gridSize;
			rect.w = gridSize;
			rect.h = gridSize;

			grid.push_back(pair<SDL_Rect, vector<Collider*>>(rect, vector<Collider*>()));
		}
	}
}

void Collision::DebugDraw()
{
	for (auto& g : grid)
	{
		SDL_SetRenderDrawColor(EngineCore::Renderer, 0, 255, 0, 255);
		SDL_RenderDrawRect(EngineCore::Renderer, &g.first);
		SDL_SetRenderDrawColor(EngineCore::Renderer, 255, 255, 255, 255);
	}
}

void Collision::UpdateGrid(Collider* collider)
{
	for (auto& g : grid)
	{
		bool colliderInsideGrid = AABB(g.first, collider->collider);
		bool gridContainsCollider = std::find(g.second.begin(), g.second.end(), collider) != g.second.end();

		if (colliderInsideGrid && !gridContainsCollider)
		{
			g.second.push_back(collider);
		}
		else if (!colliderInsideGrid && gridContainsCollider)
		{
			g.second.erase(remove(g.second.begin(), g.second.end(), collider), g.second.end());
		}
	}
}

bool Collision::AABB(const SDL_Rect& rectA, const SDL_Rect& rectB)
{
	SDL_bool b = SDL_HasIntersection(&rectA, &rectB);
	return b;
}

bool Collision::AABB(Collider& colA, Collider& colB)
{
	return AABB(colA.GetCollider(), colB.GetCollider());
}
