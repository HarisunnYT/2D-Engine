#include "Animator.h"

std::string Animator::componentName = "animator";

Animator::Animator(const char* path, Vector2 size) : SpriteRenderer(path, size)
{
}

void Animator::Init()
{
	PlayAnimation(0);

	SpriteRenderer::Init();
}

void Animator::Update()
{
	sourceRect.x = sourceRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
	sourceRect.y = animIndex * static_cast<int>(spriteSize.y);

	SpriteRenderer::Update();
}

void Animator::AddNewAnimation(const char* animName, int index, int frames, int speed)
{
	animations.emplace(make_pair(animName, Animation(index, frames, speed)));
}

void Animator::PlayAnimation(const char* animName)
{
	animIndex = animations[animName].index;
	frames = animations[animName].frames;
	speed = animations[animName].speed;
}

void Animator::PlayAnimation(int index)
{
	for (auto anim : animations)
	{
		if (anim.second.index == index)
		{
			PlayAnimation(anim.first);
		}
	}
}

std::string Animator::Parse()
{
	//std::stringstream ss;
	//{
	//	cereal::JSONOutputArchive oarchive(ss);
	//	oarchive(Animator::componentName, animations);
	//}

	//return ss.str();
	return "";
}

bool Animator::TryParse(std::string value, Entity* entity)
{
	/*std::string name;
	std::string inPath;
	std::string inSize;

	std::stringstream ss(value);
	{
		cereal::JSONInputArchive oarchive(ss);
		oarchive(name, inPath, inSize);
	}

	if (name == Animator::componentName)
	{
		entity->AddComponent<SpriteRenderer>(inPath.c_str(), Vector2::FromString(inSize));

		return true;
	}*/

	return false;
}
