#include "field.hpp"
#include "game.hpp"

Field::Field()
{
    cells = "---------";
}

char Field::getCellSymbol(const int cellIndex) const
{
    if (0 <= cellIndex && cellIndex < 9)
    {
        return cells[cellIndex];
    }
    return Game::EMPTY_FIELD_SYMBOL;
}

void Field::setCellSymbol(const int cellIndex, const char symbol)
{
    if (0 <= cellIndex && cellIndex < 9)
    {
        cells[cellIndex] = symbol;
    }
}

char Field::check()
{
    static const int maxColumns = 3;

    for (int cellIndex = 0; cellIndex < maxColumns; ++cellIndex)
    {
        if (checkRow(cellIndex) ||
            checkColumn(cellIndex) ||
            checkFirstDiagonal() ||
            checkSecondDiagonal())
        {
            return cells[cellIndex];
        }
    }
    return Game::EMPTY_FIELD_SYMBOL;
}

bool Field::checkRow(const int cellIndex)
{
    return cells[cellIndex * 3] == cells[cellIndex * 3 + 1] &&
        cells[cellIndex * 3 + 1] == cells[cellIndex * 3 + 2];
}

bool Field::checkColumn(const int cellIndex)
{
    return cells[cellIndex] == cells[cellIndex + 3] &&
        cells[cellIndex + 3] == cells[cellIndex + 6];
}

bool Field::checkFirstDiagonal()
{
    return cells[2] == cells[4] &&
        cells[4] == cells[6];
}

bool Field::checkSecondDiagonal()
{
    return cells[0] == cells[4] &&
        cells[4] == cells[8];
}