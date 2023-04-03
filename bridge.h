#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vulkan/vulkan.h>

class bridge
{
public:
	bridge(GLFWwindow* w);
	void createSurface(VkInstance instance, VkSurfaceKHR& surface);
	void waitForFramebufferSize();
	void getFramebufferSize(int* width, int* height);

private:
	GLFWwindow* window;
};

