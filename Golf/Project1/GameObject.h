#pragma once
#include "Game.h"
class GameObject {
public:
	//GameObject(const char* texSheet, SDL_Renderer* renderer);
	GameObject() {};
	~GameObject() {};

	void Update();
	void Render() { SDL_RenderCopy(renderer, objTex, NULL, &dstRect); };

	SDL_Rect getRect() { return dstRect; };

protected:
	int xpos, ypos;

	SDL_Texture* objTex;
	SDL_Rect srcRect, dstRect;
	SDL_Renderer* renderer;
};