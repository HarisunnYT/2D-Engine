#pragma once

#ifndef BRICK_H
#define BRICK_H

#include "EngineCore.h"

enum
{
	BRICK,
	ITEMSPAWNER
};

class Brick : public Component
{
public:

	Brick(int brickType);

	void FixedUpdate() override;
	void Bump();

	std::string Parse() override;
	static bool TryParse(std::string value, Entity* entity);
	static std::string componentName;

	template<class Archive>
	void Serialize(Archive& archive)
	{
		archive(componentName, brickType);
	}

private:

	int			brickType;

	bool		canBump = true;
	bool		bumping = false;
	int			bumpAmount = -20;
	float		bumpDuration = 0.1f;
	float		timer = 0.0;

	Vector3		fromPosition;
	Vector3		toPosition;
};

#endif