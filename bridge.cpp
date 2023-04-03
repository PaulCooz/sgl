#include "bridge.h"
#include "debug.h"

bridge::bridge(GLFWwindow* w) : window(w) {}

void bridge::createSurface(VkInstance instance, VkSurfaceKHR& surface)
{
	debug::assert
	(
		glfwCreateWindowSurface(instance, window, nullptr, &surface) == VK_SUCCESS,
		"failed to create window surface!"
	);
}

void bridge::waitForFramebufferSize()
{
	int width = 0, height = 0;
	glfwGetFramebufferSize(window, &width, &height);
	while (width == 0 || height == 0)
	{
		glfwGetFramebufferSize(window, &width, &height);
		glfwWaitEvents();
	}
}

void bridge::getFramebufferSize(int* width, int* height)
{
	glfwGetFramebufferSize(window, width, height);
}
