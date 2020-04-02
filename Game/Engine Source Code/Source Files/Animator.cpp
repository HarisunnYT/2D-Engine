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

void Animator::AddNewAnimation(std::string animName, int index, int frames, int speed)
{
	Animation a = Animation(animName, index, frames, speed);
	animations.push_back(a);
}

void Animator::AddNewAnimation(Animation& animation)
{
	AddNewAnimation(animation.name, animation.index, animation.frames, animation.speed);
}

void Animator::PlayAnimation(const char* animName)
{
	int i = GetAnimIndex(animName);

	animIndex = animations[i].index;
	frames = animations[i].frames;
	speed = animations[i].speed;
}

void Animator::PlayAnimation(int index)
{
	for (auto anim : animations)
	{
		if (anim.index == index)
		{
			PlayAnimation(anim.name.c_str());
		}
	}
}

int Animator::GetAnimIndex(const char* animName)
{
	for (auto& a : animations)
	{
		if (a.name == animName)
		{
			return a.index;
		}
	}
}

std::string Animator::Parse()
{
	//convert animations to string
	std::string str;

	str.append(to_string(animations.size()) + '-');

	for (auto& a : animations)
	{
		str.append(a.ToString());
		str.append(":");
	}

	animsString = str;

	std::stringstream ss;
	{
		cereal::JSONOutputArchive oarchive(ss);
		oarchive(Animator::componentName, currentPath, spriteSize.ToString(), str);
	}

	return ss.str();
}

bool Animator::TryParse(std::string value, Entity* entity)
{
	std::string name;
	std::string inPath;
	std::string inSize;
	std::string inAnimString;

	std::stringstream ss(value);
	{
		cereal::JSONInputArchive oarchive(ss);
		oarchive(name, inPath, inSize, inAnimString);
	}

	if (name == Animator::componentName)
	{
		//get vector size
		std::string vectorSizeString;
		for (char& c : inAnimString)
		{
			if (c == '-')
			{
				break;
			}
			vectorSizeString.push_back(c);
		}

		int size = stoi(vectorSizeString);
		bool clippedStart = false;

		vector<std::string> values;
		std::string currentVal;

		for (char& c : inAnimString)
		{
			if (clippedStart)
			{
				if (c == ':')
				{
					values.push_back(currentVal);
					currentVal.clear();
				}
				else
				{
					currentVal.push_back(c);
				}
			}
			else if (c == '-')
			{
				clippedStart = true;
			}
		}

		entity->AddComponent<Animator>(inPath.c_str(), Vector2::FromString(inSize));

		for (auto& s : values)
		{
			Animation anim = Animation::FromString(s);
			entity->GetComponent<Animator>().AddNewAnimation(anim);
		}

		return true;
	}

	return false;
}
