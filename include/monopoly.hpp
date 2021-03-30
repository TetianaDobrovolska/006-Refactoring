#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include "player.hpp"
#include "organisation.hpp"
#include <memory>
#include <string>
#include <vector>

class Monopoly {
public:
    Monopoly(const std::vector<std::string>& names);
    bool buy(const std::string& buyer, const std::string& org);
    bool rent(const std::string& rentee, const std::string& org);

    const std::vector<std::shared_ptr<Player>>& getPlayers() const;
    const std::vector<std::shared_ptr<Organisation>>& getOrganisations() const;
    std::shared_ptr<Player> getPlayerByName(const std::string& player);
    std::shared_ptr<Organisation> getOrganisationByName(const std::string& org);

private:
    void createPlayers(const std::vector<std::string>& names);
    void createOrganisations();

    std::vector<std::shared_ptr<Player>> _players;
    std::vector<std::shared_ptr<Organisation>> _organisations;
};

#endif
