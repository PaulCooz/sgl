#pragma once

#include "graphics.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class application
{
private:
	graphics* graphic;
	GLFWwindow* window;

public:
	application();

	bool getRunning();
	void update();

	void cleanup();
};

