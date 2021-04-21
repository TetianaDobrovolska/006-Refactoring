#ifndef UTILS
#define UTILS

#include <string>

namespace utils {

	void replaceSubstring(std::string& source, size_t& index, const std::string& target, const std::string& replacement);

	std::string replace(const std::string& source, const std::string& target, const std::string& replacement);

}

#endif