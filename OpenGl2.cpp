#include "OpenGl2.h"
#include "Display.h"

OpenGl2::OpenGl2()
{
	Display::init();
}


int OpenGl2::run()
{
	while (Display::isOpen) {
		Display::clear();
		Display::update();

		Display::handleInput();
	}
	return 0;
}

OpenGl2::~OpenGl2()
{
}
