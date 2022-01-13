#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* ball;
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

		ball = new GameObject("D:/GameDev/golf-sdl/Golf/Project1/Assets/1x/ball.png", renderer);
	}
};

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
};

void Game::update() {
	ball->Update();
};

void Game::render() {
	SDL_RenderClear(renderer);
	ball->Render();
	SDL_RenderPresent(renderer);
};

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
};