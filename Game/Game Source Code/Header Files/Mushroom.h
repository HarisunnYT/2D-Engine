#pragma once

#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "EngineCore.h"

class Mushroom : public Component
{
public:

	void Spawn();
	void FixedUpdate() override;

	std::string Parse() override;
	static bool TryParse(std::string value, Entity* entity);
	static std::string componentName;

	template<class Archive>
	void Serialize(Archive& archive)
	{
		archive(componentName);
	}

private:

	bool		spawning = false;
	int			bumpAmount = -32;
	float		bumpDuration = 0.5f;
	float		timer = 0.0;

	Vector3		fromPosition;
	Vector3		toPosition;

};

#endif