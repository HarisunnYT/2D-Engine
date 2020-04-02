#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include "Entity.h"
#include "EngineCore.h"

class Entity;
class Transform;
class Camera : public Entity
{
public:

	Camera();

	void Update() override;

	SDL_Rect offset;

private:

	Transform* transform;

};

#endif