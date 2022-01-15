#include "Player.h"
#include "TextureManager.h"


Player::Player(const char* texSheet, SDL_Renderer* ren) {
	renderer = ren;
	objTex = TextureManager::LoadTexture(texSheet, renderer);
	xpos = 0;
	ypos = 0;
	dstRect.h = 32;
	dstRect.w = 32;
};