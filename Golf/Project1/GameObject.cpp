#include "GameObject.h"
#include "TextureManager.h";
//GameObject::GameObject(const char* texSheet, SDL_Renderer* ren) {
//	renderer = ren;
//	objTex = TextureManager::LoadTexture(texSheet, renderer);
//	xpos = 0;
//	ypos = 0;
//	dstRect.h = 32;
//	dstRect.w = 32;
//}
//GameObject::GameObject() {};

void GameObject::Update() {
	xpos++;
	ypos++;


	dstRect.x = xpos;
	dstRect.y = ypos;
};
