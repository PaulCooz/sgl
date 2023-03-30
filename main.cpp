#include "graphics.h"
#include "application.h"
#include "debug.h"

int main()
{
	application* app = new application();

	while (app->get_running())
	{
		app->update();
	}

	app->cleanup();
}