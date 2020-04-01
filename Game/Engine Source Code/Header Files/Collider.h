#pragma once

#ifndef COLLIDER_H
#define COLLIDER_H

#include "EngineCore.h"

class Transform;
class SpriteRenderer;

class Collider : public Component
{
public:

	Collider(std::string tag);

	void Init() override;
	void Update() override;
	void DebugDraw() override;

	void SetSize(Vector2 size);
	void SetOffset(Vector2 offset);

	const SDL_Rect GetCollider();

	std::string Parse() override;
	static bool TryParse(std::string value, Entity* entity);
	static std::string componentName;

	template<class Archive>
	void Serialize(Archive& archive)
	{
		archive(componentName, offset.ToString(), size.ToString());
	}

	std::string Tag;

private:

	void UpdateCollider();

	Transform*			transform = nullptr;
	SpriteRenderer*		spriteRenderer = nullptr;

	Vector2				offset;
	Vector2				size;

	SDL_Rect			collider;
};

#endif