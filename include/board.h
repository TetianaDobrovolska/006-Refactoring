#ifndef _BOARD_H_
#define _BOARD_H_

class Board {
public:
    static constexpr int kMaxCellCount = 9;
    static constexpr int kMinStepsToWin = 5;
    static constexpr int kRowSize = 3;
    static const char kDefaultSymbol = '-';
    static const char kOSymbol = 'O';
    static const char kXSymbol = 'X';

    Board();

    const char getCellByIndex(const int& index) const;
    bool setCell(const int& index, const char symbol);
    bool isCellValid(const int& cell);

    char checkWinner();
    void showBoard();

private:
    bool isHorizontalLine(const int& index);
    bool isVerticalLine(const int& index);
    bool isRightDiagonalLine();
    bool isLeftDiagonalLine();

    char cells[kMaxCellCount];
};

#endif  //_BOARD_H_
