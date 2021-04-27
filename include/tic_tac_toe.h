#ifndef _TIC_TAC_TOE_H_
#define _TIC_TAC_TOE_H_

#include <string>
#include <vector>

#include "player.h"

class TicTacToe {
public:
    static constexpr int kMaxCellCount = 9;
    static constexpr int kMinStepsToWin = 5;
    static constexpr int kMaxNameSize = 80;
    static constexpr int kRowSize = 3;
    static const char kDefaultSymbol = '-';
    const char kOSymbol = 'O';
    const char kXSymbol = 'X';

    TicTacToe(const char name[kMaxNameSize], const char name2[kMaxNameSize]);

    const char * getFirstPlayer() const;
    const char * getSecondPlayer() const;
    const char getCellByIndex(const int&) const;

    bool make_move(const int& num, const int& cell);
    char check_winner();
    void result();
    void show_cells();

private:
    bool isCellValid(const int& cell);
    bool isHorizontalLine(const int& index);
    bool isVerticalLine(const int& index);
    bool isRightDiagonalLine();
    bool isLeftDiagonalLine();

    char winSymbol;
    char cells[kMaxCellCount];
    std::vector<Player> Players;
};

#endif  //_TIC_TAC_TOE_H_
