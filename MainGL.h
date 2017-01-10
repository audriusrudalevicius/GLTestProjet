#pragma once

#include <GL/glew.h>
#include <SDL/SDL.h>

enum class GameState {PLAY, EXIT};

class MainGL
{
public:
	MainGL();
	~MainGL();

	int run();
private:
	SDL_Window* _window;
	int _screenWidth;
	int _screenHeigh;
	GameState _gameState;

	void initSystems();
	void proccessInput();
	void glLoop();
	void draw();
};

