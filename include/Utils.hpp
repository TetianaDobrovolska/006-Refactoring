#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

namespace Utils {
	static const char BEGIN_DESK_LETTER = 'A';
	static const char END_DESK_LETTER = 'H';
	static const char BEGIN_DESK_DIGIT = '1';
	static const char END_DESK_DIGIT = '8';

	bool IsFigureInDeskHeight(const char);
	bool IsFigureInDeskWidth(const char);
	bool IsFigureInDesk(const std::string&);
}

#endif
