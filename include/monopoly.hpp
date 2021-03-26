#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <list>
#include <tuple>
#include <string>

class Monopoly
{
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
	Monopoly(std::string names[10],int);
	std::list<std::tuple<std::string,int>> *	GetPlayersList();
	std::list<std::tuple<std::string, Type, int,bool>> * GetFieldsList();
	std::tuple<std::string, int>  GetPlayerInfo(int);	 
	bool buy(int p,std::tuple<std::string, Type, int, bool>);
	std::tuple<std::string, Type, int, bool> GetFieldByName(std::string);	
	bool rent(int p, std::tuple<std::string, Type, int, bool>c);

    std::list<std::tuple<std::string, Type, int, bool>> m_fields;
    std::list<std::tuple<std::string, int>> m_players;
	
};

#endif
