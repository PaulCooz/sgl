#pragma once

#include <vulkan/vulkan.h>
#include <vector>

class graphics
{
private:
	VkInstance instance;
	VkDebugUtilsMessengerEXT debugMessenger;

	VkResult CreateDebugUtilsMessengerEXT
	(
		VkInstance instance,
		const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
		const VkAllocationCallbacks* pAllocator,
		VkDebugUtilsMessengerEXT* pDebugMessenger
	);
	void DestroyDebugUtilsMessengerEXT
	(
		VkInstance instance,
		VkDebugUtilsMessengerEXT debugMessenger,
		const VkAllocationCallbacks* pAllocator
	);
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
	void setupDebugMessenger();

	bool checkValidationLayerSupport();

public:
	graphics(std::vector<const char*> extensions);
	void cleanup();
};

