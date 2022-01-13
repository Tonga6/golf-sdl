#pragma once
#include "iostream"]
#include "SDL.h"
class Game {
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height);
	void handleEvents();
	void update();
	void render();
	void clean();

	bool checkRunning() { return isRunning; };
private:
	bool isRunning = false;
	SDL_Window *window;
	SDL_Renderer* renderer;

};