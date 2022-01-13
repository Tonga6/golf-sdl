#pragma once
#include "Game.h"
class GameObject {
public:
	GameObject(const char* texSheet, SDL_Renderer* renderer);
	~GameObject();

	void Update();
	void Render();
private:
	int xpos, ypos;

	SDL_Texture* objTex;
	SDL_Rect srcRect, dstRect;
	SDL_Renderer* renderer;
};