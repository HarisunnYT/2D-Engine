#include "Collision.h"
#include "Collider.h"
#include "Camera.h"

int squareSize = 500;
Vector2 gridSize = Vector2(20, 2);

vector<pair<SDL_Rect, vector<Collider*>>> Collision::grid;

bool Collision::drawGrid = false;

SDL_Rect tempRec;

void Collision::Init()
{
	int cols = static_cast<int>(gridSize.x);
	int rows = static_cast<int>(gridSize.y);

	for (int x = 0; x < cols; x++)
	{
		for (int y = 0; y < rows; y++)
		{
			SDL_Rect rect;

			rect.x = x * squareSize;
			rect.y = y * squareSize;
			rect.w = squareSize;
			rect.h = squareSize;

			grid.push_back(pair<SDL_Rect, vector<Collider*>>(rect, vector<Collider*>()));
		}
	}
}

void Collision::DebugDraw()
{
	if (Collision::drawGrid)
	{
		for (auto& g : grid)
		{
			tempRec.x = g.first.x - EngineCore::camera->offset.x;
			tempRec.y = g.first.y - EngineCore::camera->offset.y;
			tempRec.w = squareSize;
			tempRec.h = squareSize;

			SDL_SetRenderDrawColor(EngineCore::Renderer, 0, 255, 0, 255);
			SDL_RenderDrawRect(EngineCore::Renderer, &tempRec);
			SDL_SetRenderDrawColor(EngineCore::Renderer, 255, 255, 255, 255);
		}
	}
}

void Collision::UpdateGrid(Collider* collider)
{
	if (collider->Trigger)
	{
		return;
	}

	//add collider to correct grid
	for (auto& g : grid)
	{
		bool colliderInsideGrid = AABB(g.first, collider->collider);
		bool gridContainsCollider = std::find(g.second.begin(), g.second.end(), collider) != g.second.end();

		if (colliderInsideGrid && !gridContainsCollider)
		{
			g.second.push_back(collider);
		}
		else if (!colliderInsideGrid && gridContainsCollider || (gridContainsCollider && !collider->entity->IsActive()))
		{
			g.second.erase(remove(g.second.begin(), g.second.end(), collider), g.second.end());
		}
	}
}

void Collision::CheckCollision(Collider* collider)
{
	for (auto& g : Collision::grid)
	{
		tempRec.x = g.first.x - EngineCore::camera->offset.x;
		tempRec.y = g.first.y - EngineCore::camera->offset.y;
		tempRec.w = squareSize;
		tempRec.h = squareSize;

		if (AABB(collider->collider, tempRec))
		{
			for (auto& c : g.second)
			{
				if (c != collider && !c->Trigger && c->entity->IsActive())
				{
					Vector2 otherPosition = c->Centre();
					Vector2 otherHalfSize = Vector2((float)c->collider.w / 2, (float)c->collider.h / 2);

					Vector2 thisPosition = collider->Centre();
					Vector2 thisHalfSize = Vector2((float)collider->collider.w / 2, (float)collider->collider.h / 2);

					float deltaX = otherPosition.x - thisPosition.x;
					float deltaY = otherPosition.y - thisPosition.y;
					float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
					float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

					float push = 1.0f;

					Transform* thisTransform = &collider->entity->GetComponent<Transform>();
					Rigidbody* thisRigidbody = &collider->entity->GetComponent<Rigidbody>();

					Vector3 pos = thisTransform->GetPosition();

					if (intersectX < 0.0 && intersectY < 0.0f)
					{
						if (intersectX > intersectY)
						{
							if (deltaX > 0.0f)
							{
								thisTransform->SetPosition(Vector3(pos.x + intersectX, pos.y, pos.z));
								if (thisRigidbody->GetVelocity().x > 0)
								{
									thisRigidbody->SetVelocity(Vector2(0, thisRigidbody->GetVelocity().y));
								}
							}
							else
							{
								thisTransform->SetPosition(Vector3(pos.x - intersectX, pos.y, pos.z));
								if (thisRigidbody->GetVelocity().x < 0)
								{
									thisRigidbody->SetVelocity(Vector2(0, thisRigidbody->GetVelocity().y));
								}
							}
						}
						else
						{
							if (deltaY > 0.0f)
							{
								thisTransform->SetPosition(Vector3(pos.x, pos.y + intersectY, pos.z));
								if (thisRigidbody->GetVelocity().y < 0) 
								{
									thisRigidbody->SetVelocity(Vector2(thisRigidbody->GetVelocity().x, 0));
								}
							}
							else
							{
								thisTransform->SetPosition(Vector3(pos.x, pos.y - intersectY, pos.z));
								if (thisRigidbody->GetVelocity().y > 0)
								{
									thisRigidbody->SetVelocity(Vector2(thisRigidbody->GetVelocity().x, 0));
								}
							}
						}

						return;
					}
				}
			}
		}
	}

	return;
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
