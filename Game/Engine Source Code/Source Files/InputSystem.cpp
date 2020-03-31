#include "InputSystem.h"

vector<int> InputSystem::keysHeld;

bool InputSystem::KeyHeld(int SDL_CODE)
{
	return std::find(keysHeld.begin(), keysHeld.end(), SDL_CODE) != keysHeld.end();
}

bool InputSystem::KeyPressed(int SDL_CODE)
{
	if (EngineCore::Event.type == SDL_KEYDOWN)
	{
		return EngineCore::Event.key.keysym.sym == SDL_CODE;
	}

	return false;
}

bool InputSystem::KeyReleased(int SDL_CODE)
{
	if (EngineCore::Event.type == SDL_KEYUP)
	{
		return EngineCore::Event.key.keysym.sym == SDL_CODE;
	}

	return false;
}

void InputSystem::Update()
{
	int key = EngineCore::Event.key.keysym.sym;
	if (EngineCore::Event.type == SDL_KEYDOWN && !KeyHeld(key))
	{
		keysHeld.push_back(key);
	}
	if (EngineCore::Event.type == SDL_KEYUP)
	{
		keysHeld.erase(remove(keysHeld.begin(), keysHeld.end(), key), keysHeld.end());
	}
}
