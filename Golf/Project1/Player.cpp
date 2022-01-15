#include "Player.h"
#include "TextureManager.h"


Player::Player(const char* texSheet, SDL_Renderer* ren) {
	renderer = ren;
	objTex = TextureManager::LoadTexture(texSheet, renderer);
	pos->x = 0;
	pos->y = 0;
	dstRect.h = 32;
	dstRect.w = 32;
};

void Player::Update() {
	pos->x += 1;
	pos->y += 1;

	dstRect.x = pos->x;
	dstRect.y = pos->y;

};

bool Player::IsMouseOver(Vec2* mousePos) {
	mousePos->x -= pos->x;
	mousePos->y -= pos->y;
	if ((mousePos->x <= 32 && mousePos->x >= -32) && (mousePos->y <= 32 && mousePos->y >= -32))
		return true;

	return false;
}