#include "MainGL2.h"
#include "Display.h"
#include "Application.h"

MainGL2::MainGL2()
{
	Display::init();
}


int MainGL2::run()
{
	Application app;

	app.runMainLoop();

	return 0;
}

MainGL2::~MainGL2()
{
}
