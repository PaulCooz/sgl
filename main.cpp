#include "graphics.h"
#include "application.h"
#include "debug.h"

int main()
{
	application* app = new application();

	while (app->getRunning())
	{
		app->update();
	}

	app->cleanup();
}