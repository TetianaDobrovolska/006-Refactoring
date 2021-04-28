#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include "player.hpp"
#include "field.hpp"

#include <list>
#include <tuple>
#include <string>

class Monopoly
{
public:

    static constexpr const int startupCapital = 6000;

    static constexpr const int maxPlayersCount = 10;

    static constexpr const int rentalPriceAuto = 250;
    static constexpr const int rentalPriceTravel = 250;
    static constexpr const int rentalPriceClothes = 250;
    static constexpr const int rentalPricePrison = 1000;
    static constexpr const int rentalPriceBank = 700;

    static constexpr const int sellPriceAuto = 500;
    static constexpr const int sellPriceTravel = 700;
    static constexpr const int sellPriceClothes = 100;
    static constexpr const int sellPriceFood = 250;

    Monopoly(const std::string names[maxPlayersCount], const int&);
    const std::list<Player>& GetPlayersList() const;
    const std::list<Field>& GetFieldsList() const;
    const Player& GetPlayerInfo(const int&) const;
    const Field& GetFieldByName(const std::string&) const;

    bool Buy(const int& p, Field&);
    bool Renta(const int& p, Field&);

private:
    std::list<Field> Fields;
    std::list<Player> Players;

};

#endif
