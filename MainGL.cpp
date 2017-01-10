#include "MainGL.h"
#include <iostream>
#include <string>
#include <stdexcept>

void FatalError(std::string er)
{
	std::cout << "Fatal: " << er << std::endl;
	int readKey;
	std::cin >> readKey;
	exit(1);
}

MainGL::MainGL()
{
	_window = nullptr;
	_screenWidth = 1024;
	_screenHeigh = 768;
	_gameState = GameState::PLAY;
}

MainGL::~MainGL()
{
}

int MainGL::run() {
	initSystems();
	glLoop();
	return 0;
}

void MainGL::initSystems()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	_window = SDL_CreateWindow("Main window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeigh, SDL_WINDOW_OPENGL);
	if (_window == nullptr) {
		FatalError("SDL Cannot create window!");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);

	if (glContext == nullptr) {
		FatalError("SDL SDL_GLContext could not be set up!");
	}

	GLenum error = glewInit();
	if (errno != GLEW_OK) {
		FatalError("GLEW could not be set up!");
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); // Remove flickering with two buffers. 
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void MainGL::proccessInput()
{
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		switch (evnt.type) {
			case SDL_QUIT:
				_gameState = GameState::EXIT;
				break;
		}
	}
}

void MainGL::glLoop()
{
	while (_gameState != GameState::EXIT)
	{
		proccessInput();
		draw();
	}
}

void MainGL::draw()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnableClientState(GL_COLOR_ARRAY);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0, 1);
	glVertex2f(15, 500);
	glVertex2f(500, 500);
	glEnd();



	SDL_GL_SwapWindow(_window);
}
