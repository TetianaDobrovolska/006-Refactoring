#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <list>
#include <string>
#include <tuple>

class Monopoly
{
private:
	static const int kMaxPlayerCount = 10;
public:
	enum Type
	{
		AUTO,
		FOOD,
		TRAVEL,
		CLOTHER,
		PRISON,
		BANK
	};
	Monopoly(const std::string names[kMaxPlayerCount], const int&);

    const std::list<std::tuple<std::string, int>>& GetPlayersList() const;
    const std::list<std::tuple<std::string, Type, int, bool>>& GetFieldsList() const;
    const std::tuple<std::string, int>& GetPlayerInfo(const int&) const;
    const std::tuple<std::string, Type, int, bool>& GetFieldByName(const std::string&) const;

	bool Buy(const int& p, std::tuple<std::string, Type, int, bool>&);
	bool Renta(const int& p, std::tuple<std::string, Type, int, bool>&);

private:
	std::list<std::tuple<std::string, int>> Players;
	std::list<std::tuple<std::string, Type, int, bool>> Fields;
};

#endif
