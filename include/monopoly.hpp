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
		const std::list<std::tuple<std::string,int>> *GetPlayersList();
		const std::list<std::tuple<std::string, Type, int,bool>> *GetFieldsList();
		std::tuple<std::string, int>  GetPlayerInfo(int);
		std::tuple<std::string, Type, int, bool> GetFieldByName(std::string);

		bool Buy(int,std::tuple<std::string, Type, int, bool>);
		bool Renta(int, std::tuple<std::string, Type, int, bool>);
		
		void UpdatePlayerCash(int, int);
		void UpdateFieldOwner(std::string, int);
	
	private:
		std::list<std::tuple<std::string, Type, int, bool>> Fields;
		std::list<std::tuple<std::string, int>> Players;

};

#endif