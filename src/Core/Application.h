#pragma once

#include <stack>
#include <memory>

#include "State\Game_State.h"

class Application
{
public:
	Application();

	void runMainLoop();
	void pushState(std::unique_ptr<State::Game_State>state);
	void popState();
private:
	std::stack<std::unique_ptr<State::Game_State>> m_states;
};