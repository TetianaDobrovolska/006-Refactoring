#include "monopoly.hpp"
#include "auto.hpp"
#include "bank.hpp"
#include "clothes.hpp"
#include "food.hpp"
#include "prison.hpp"
#include "travel.hpp"

using namespace ::std;
typedef std::shared_ptr<Organisation> OrgPtr_t;
typedef std::vector<std::shared_ptr<Organisation>> Vec_OrgPtr_t;
typedef std::shared_ptr<Player> PlayerPtr_t;

Monopoly::Monopoly(const vector<string>& names) {
    createPlayers(names);
    createOrganisations();
}

void Monopoly::createPlayers(const vector<string>& names) {
    for(const auto& name : names) {
        _players.push_back(make_shared<Player>(name, 6000));
    }
}

void Monopoly::createOrganisations() {
    _organisations.push_back(make_shared<Auto>("Ford"));
    _organisations.push_back(make_shared<Food>("MCDonald"));
    _organisations.push_back(make_shared<Clothes>("Lamoda"));
    _organisations.push_back(make_shared<Travel>("Air Baltic"));
    _organisations.push_back(make_shared<Travel>("Nordavia"));
    _organisations.push_back(make_shared<Prison>());
    _organisations.push_back(make_shared<Auto>("TESLA"));
}

bool Monopoly::buy(const std::string& buyer, const std::string& org) {
    const auto org_ptr = getOrganisationByName(org);
    if (!org_ptr->isForSale())
        return false;

    const auto buyer_ptr = getPlayerByName(buyer);
    const auto amount = org_ptr->getValue();
    if (!Player::makeTransaction(amount, *buyer_ptr))
        return false;

    org_ptr->setOwner(buyer_ptr->getName());
    return true;
}

bool Monopoly::rent(const std::string& rentee, const std::string& org) {
    const auto org_ptr = getOrganisationByName(org);
    if (!org_ptr->isForRent())
        return false;
    const auto rentee_ptr = getPlayerByName(rentee);
    const auto owner_ptr = getPlayerByName(org_ptr->getOwner());
    const auto amount = org_ptr->getRent();
    if (!Player::makeTransaction(amount, *rentee_ptr, *owner_ptr))
        return false;
    return true;
}

const std::vector<std::shared_ptr<Player>>& Monopoly::getPlayers() const {
    return _players;
}

const Vec_OrgPtr_t& Monopoly::getOrganisations() const {
    return _organisations;
}

OrgPtr_t Monopoly::getOrganisationByName(const std::string& org) {
    OrgPtr_t result = nullptr;
    for (const auto& org_ptr : _organisations) {
        if(org_ptr->getName() == org) {
            result = org_ptr;
        }
    }
    return result;
}

PlayerPtr_t Monopoly::getPlayerByName(const std::string& player) {
    PlayerPtr_t result = nullptr;
    for (const auto& player_ptr : _players) {
        if(player_ptr->getName() == player) {
            result = player_ptr;
        }
    }
    return result;
}
