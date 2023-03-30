#pragma once

#include <string>

class debug
{
public:
	static void assert(bool condition, std::string error_message);
	static void log(std::string log, bool is_priority);

private:
	debug();
};

