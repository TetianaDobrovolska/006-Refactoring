#ifndef _TIC_TAC_TOE_H_
#define _TIC_TAC_TOE_H_

#include <string>
#include <vector>

#include "board.h"
#include "player.h"

class TicTacToe {
public:
    TicTacToe(const char name[Player::kMaxNameSize], const char name2[Player::kMaxNameSize]);

    const char * getFirstPlayer() const;
    const char * getSecondPlayer() const;
    const char getCellByIndex(const int&) const;

    bool make_move(const int& playerId, const int& cell);
    char check_winner();

    void play();
    void show_result();
    void show_cells();

private:
    char winSymbol;
    Board board;
    std::vector<Player> Players;
};

#endif  //_TIC_TAC_TOE_H_
