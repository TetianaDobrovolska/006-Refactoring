#ifndef CHESS_FIGURE_HPP
#define CHESS_FIGURE_HPP

#include <regex>
#include <string>

class ChessFigure {
public:
    struct TargetMove {
        std::string target;
        bool isOccupiedBySelf;
        bool isOccupiedByOpponent;
        bool isBlockedLineOfSight;
        bool isGuarded;
        bool isKingCheckedAfterMove;
    };

    virtual bool move(const TargetMove& targetMove) = 0;
    virtual ~ChessFigure();

protected:
    ChessFigure(const std::string& coord);
    virtual bool isValidMove(const TargetMove& targetMove) = 0;
    bool isValidTarget(const std::string& target);

    std::string _currentCoord;
    std::regex _regex;
};

#endif
