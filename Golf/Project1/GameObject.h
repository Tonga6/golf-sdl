#pragma once
#include "Game.h"


class GameObject {
public:
	//GameObject(const char* texSheet, SDL_Renderer* renderer);
	GameObject() {};
	~GameObject() {};

	void Render() { SDL_RenderCopy(renderer, objTex, NULL, &dstRect); };

	SDL_Rect getRect() { return dstRect; };
	Vec2* GetPos() { return pos; };
protected:
	Vec2* pos = (Vec2*) malloc(sizeof(Vec2));
	SDL_Texture* objTex;
	SDL_Rect srcRect, dstRect;
	SDL_Renderer* renderer;
};