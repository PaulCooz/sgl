#include "application.h"

#include <vector>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

application::application()
{
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);

	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
	std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

	graphic = new graphics(extensions);
}

bool application::get_running()
{
	return !glfwWindowShouldClose(window);
}

void application::update()
{
	glfwPollEvents();
}

void application::cleanup()
{
	graphic->cleanup();

	glfwDestroyWindow(window);
	glfwTerminate();
}
