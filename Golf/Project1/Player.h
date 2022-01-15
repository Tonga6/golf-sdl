#pragma once
#include "GameObject.h"
class Player : public GameObject {
public:
	Player();
	Player(const char* texSheet, SDL_Renderer* renderer);
	bool isIntersecting(SDL_Rect rect) { return SDL_HasIntersection(&GameObject::getRect(), &rect); };
};