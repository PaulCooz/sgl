#include "debug.h"

#include <iostream>
#include <string>

void debug::assert(bool condition, std::string error_message)
{
	if (!condition)
	{
		log(error_message, true);
		throw std::runtime_error(error_message);
	}
}

void debug::log(std::string log, bool is_priority)
{
	std::cout << (is_priority ? "!!!\t" : "\t") << log << std::endl;
}
