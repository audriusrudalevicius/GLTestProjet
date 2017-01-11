#include "Playing.h"

#include <iostream>

namespace State
{
	Playing::Playing(Application & application) : Game_State(application), m_model({
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	})
	{
	}

	void Playing::input()
	{

	}

	void Playing::update()
	{

	}

	void Playing::draw()
	{
		m_model.bind();
		glDrawArrays(GL_TRIANGLES, 0, 3);
		m_model.unbind();
	}
}
