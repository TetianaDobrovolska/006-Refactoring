#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <list>
#include <vector>
#include <string>

#include "player.hpp"
#include "field.hpp"

class Monopoly
{

public:
	Monopoly(std::vector<std::string>, int);
	~Monopoly();

	std::vector<Player *> players() const { return m_players; }
	std::vector<Field *> fields() const { return m_fields; }

	bool byuField(Player *, Field *);

	bool rentField(Player *, Field *);

private:
	std::vector<Player *> m_players;
	std::vector<Field *> m_fields;


};

#endif