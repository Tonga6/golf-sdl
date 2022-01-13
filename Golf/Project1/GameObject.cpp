#include "GameObject.h"
#include "TextureManager.h";
GameObject::GameObject(const char* texSheet, SDL_Renderer* ren) {
	renderer = ren;
	objTex = TextureManager::LoadTexture(texSheet, renderer);
	xpos = 0;
	ypos = 0;
}

void GameObject::Update() {
	xpos++;
	ypos++;
	dstRect.h = 32;
	dstRect.w = 32;
	dstRect.x = xpos;
	dstRect.y = ypos;
}

void GameObject::Render() {
	SDL_RenderCopy(renderer, objTex, NULL, &dstRect);
}