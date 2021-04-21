#include "utils.hpp"

namespace utils {

	void replaceSubstring(std::string& source, size_t& index, const std::string& target, const std::string& replacement)
	{
		index = source.find(target[0], index);
		if (index == std::string::npos) {
			return;
		}
		for (auto j = 0; j < target.length(); ++j) {
			if (target[j] != source[index + j]) {
				++index;
				return;
			}
		}
		source = source.replace(source.begin() + index,
			source.begin() + index + target.length(),
			replacement.cbegin(),
			replacement.cend());
	}

	std::string replace(const std::string& source, const std::string& target, const std::string& replacement)
	{
		if (target.length() == 0) {
			return source;
		}

		std::string _source = source;
		size_t index = 0;
		while (index != std::string::npos) {
			replaceSubstring(_source, index, target, replacement);
		}
		return _source;
	}

}
