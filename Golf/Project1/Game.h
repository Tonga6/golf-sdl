#pragma once
#include "iostream"
#include "SDL.h"
#include "SDL_image.h"
struct Vec2 {
	int x, y;
};


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

	template <typename T>
	static void Log(T var) { std::cout << var << std::endl; };

	float GetDistance(Vec2* a, Vec2* b);
private:
	bool isLMBDown = false;
	Vec2* mousePos = (Vec2*)malloc(sizeof(Vec2));
	Uint32 button;
	bool isRunning = false;
	SDL_Window *window;
	SDL_Renderer* renderer;

};