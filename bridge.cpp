#include "bridge.h"
#include "debug.h"

bridge::bridge(GLFWwindow* w) : window(w) {}

void bridge::create_surface(VkInstance instance, VkSurfaceKHR& surface)
{
	debug::assert
	(
		glfwCreateWindowSurface(instance, window, nullptr, &surface) == VK_SUCCESS,
		"failed to create window surface!"
	);
}

void bridge::getFramebufferSize(int* width, int* height)
{
	glfwGetFramebufferSize(window, width, height);
}
