#include "Game.h"
#include "TextureManager.h"
#include "Player.h"
#include "Terrain.h"
Player* ball;
Terrain* block;
Game::Game() {

}

Game::~Game() {

}
//set up SDL window and renderer
void Game::init(const char* title, int xpos, int ypos, int width, int height) {
	int flags = 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window == 0) {
			std::cout << "Error creating window" << std::endl;
			return;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer == 0) {
			std::cout << "Error creating renderer" << std::endl;
			return;
		}
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		isRunning = true;

		ball = new Player("Assets/1x/ball.png", renderer);
		block = new Terrain("Assets/1x/block.png", renderer);
	}
};

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_MOUSEBUTTONDOWN:
		button = SDL_GetMouseState(&mousePos->x, &mousePos->y);

		if ((button & SDL_BUTTON_LMASK) != 0 && ball->IsMouseOver(mousePos)) {
			isLMBDown = true;
			Log("LMB Down over ball");
		}
		break;
	case SDL_MOUSEBUTTONUP:
		if (isLMBDown) {
			button = SDL_GetMouseState(&mousePos->x, &mousePos->y);

			Log("LMB Up");
			Log(GetDistance(mousePos, ball->GetPos()));
			isLMBDown = false;
		}
		break;
	default:
		break;
	}
};

void Game::update() {
	//ball->Update();
};

void Game::render() {
	SDL_RenderClear(renderer);
	ball->Render();
	//block->Render();
	SDL_RenderPresent(renderer);
};

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
};

float Game::GetDistance(Vec2* a, Vec2* b) {
	float distance = sqrt((a->x - b->x)^2 + (a->y - b->y)^2);
	return distance;
}