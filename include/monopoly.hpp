#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <string>
#include <tuple>
#include <vector>

class Monopoly {
public:
    enum FieldType {
        AUTO,
        FOOD,
        TRAVEL,
        CLOTHES,
        PRISON,
        BANK
	};

    Monopoly(const std::vector<std::string>& names, const int& countPlayers);
    bool buy(const int& buyerId, std::tuple<std::string, FieldType, int, bool>& field);
    bool rent(const int& renterId, std::tuple<std::string, FieldType, int, bool>& field);

    std::vector<std::tuple<std::string,int>> getPlayers() const;
    std::vector<std::tuple<std::string, FieldType, int,bool>> getFields() const;
    std::tuple<std::string, int> getPlayer(const int& index) const;
    std::tuple<std::string, FieldType, int, bool> getFieldByName(std::string field);

private:
    std::vector<std::tuple<std::string, FieldType, int, bool>> _fields;
    std::vector<std::tuple<std::string, int>> _players;
};

#endif
