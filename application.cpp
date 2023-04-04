#include "application.h"
#include "bridge.h"

#include <vector>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

static void framebufferResizeCallback(GLFWwindow* window, int width, int height)
{
	auto graphic = reinterpret_cast<graphics*>(glfwGetWindowUserPointer(window));
	graphic->framebufferResized = true;
}

application::application()
{
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

	window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);

	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
	std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

	bridge* b = new bridge(window);
	graphic = new graphics(extensions, *b);

	glfwSetWindowUserPointer(window, graphic);
	glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
}

bool application::getRunning()
{
	return !glfwWindowShouldClose(window);
}

void application::update()
{
	glfwPollEvents();
	graphic->drawFrame();
}

void application::cleanup()
{
	graphic->cleanup();

	glfwDestroyWindow(window);
	glfwTerminate();
}
