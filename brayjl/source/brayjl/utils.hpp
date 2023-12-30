#ifndef UTILS_HPP
#define UTILS_HPP

#include "brayjl/logger.hpp"

#include <string>
#include <fstream>
#include <stdexcept>
#include <iostream>

namespace brayjl {
	struct utils {
		static std::string readFile(std::string filepath);
	};
}

#endif // !UTILS_HPP