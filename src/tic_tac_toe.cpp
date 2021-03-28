#include <iostream> 
#include <cstring> 
#include <clocale>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int ROW_COUNT = 3;
const int NUM_OF_CELLS = ROW_COUNT * ROW_COUNT;

const char CELL_EMPTY = '-';
const char CELL_PLAYER1 = 'X';
const char CELL_PLAYER2 = '0';

const int MAX_NAME_LENGTH = 80;
const int CELL_START_NUM = 1;
const int COUNT_START_CHECK = 5;

struct Player
{
    string playerName;
    char chessType;
    int turn;
    bool win;

    void setWinResult(const char result) {
        win = result == chessType;
    }

    void printResultIfWin(const Player &competitor) {
        if (win)
            cout << playerName << "you won congratulations " << competitor.playerName << " you lose..." << endl;
    }


};

struct BoardGame {
    Player Player1, Player2;
    char cells[NUM_OF_CELLS];

    void initCells() {
        for (int i = 0; i < NUM_OF_CELLS; i++) cells[i] = CELL_EMPTY;
    }

    bool isCellNumInvalid(int inputCell) {
        return (inputCell > NUM_OF_CELLS || inputCell < CELL_START_NUM);
    }

    bool isCellNotEmpty(int inputCell) {
        return cells[inputCell - CELL_START_NUM] != CELL_EMPTY;
    }

    void inputRequest() {
        char PlayerName1[MAX_NAME_LENGTH], PlayerName2[MAX_NAME_LENGTH];
        do {
            cout << "Enter the name of the first player: ";
            std::cin >> PlayerName1;

            cout << "Enter the name of the seecond player: ";
            std::cin >> PlayerName2;
        } while (!strcmp(PlayerName1, PlayerName2));
    
        Player1.playerName = PlayerName1;
        Player1.chessType = CELL_PLAYER1;
        Player1.turn = CELL_START_NUM % 2;
        Player2.playerName = PlayerName2;
        Player2.chessType = CELL_PLAYER2;
        Player2.turn = CELL_START_NUM % 2;

        initCells();
    }

    void show_cells() {
        system("cls");

        cout << "Cell numbers: \n";
        cout << "-" << 1 << "-" << "|" << "-" << 2 << "-" << "|" << "-" << 3 << "-" << endl;
        cout << "-" << 4 << "-" << "|" << "-" << 5 << "-" << "|" << "-" << 6 << "-" << endl;
        cout << "-" << 7 << "-" << "|" << "-" << 8 << "-" << "|" << "-" << 9 << "-" << endl;

        cout << "Current situation (--- empty):\n" << endl;
        cout << "-" << cells[0] << "-" << '|' << "-" << cells[1] << "-" << '|' << "-" << cells[2] << "-" << endl;
        cout << "-" << cells[3] << "-" << '|' << "-" << cells[4] << "-" << '|' << "-" << cells[5] << "-" << endl;
        cout << "-" << cells[6] << "-" << '|' << "-" << cells[7] << "-" << '|' << "-" << cells[8] << "-" << "\n" << endl;

    }

    void checkTurnAndMakeMove(const int currentTurn, const Player &player) {
        if (currentTurn % 2 != player.turn) return;

        int cell;
        cout << player.playerName << ",enter cell number, make your move:";
        cin >> cell;

        while (isCellNumInvalid(cell) || isCellNotEmpty(cell)) {
            cout << "Enter the number of the correct (1-9) or empty (---) cells to make a move:";
	    cin >> cell;
            cout << "\n";
        }
    
        cells[cell - CELL_START_NUM] = player.chessType;
    }

    void start() {
        char win = CELL_EMPTY; 
        show_cells();
        for (int move = CELL_START_NUM; move <= NUM_OF_CELLS; move++) {
            checkTurnAndMakeMove(move, Player1);
            checkTurnAndMakeMove(move, Player2);

            show_cells();
        
            if (move >= COUNT_START_CHECK)
            {
                win = check();
                if (win != CELL_EMPTY)
                    break;
            }

        }
        Player1.setWinResult(win);
        Player2.setWinResult(win);
    }

    bool checkRow(int row) {
        return cells[row * ROW_COUNT] == cells [row * ROW_COUNT + 1] && cells[row * ROW_COUNT] == cells[row * ROW_COUNT + 2];
    }

    bool checkCol(int col) {
        return cells[col] == cells [col + ROW_COUNT] && cells[col] == cells[col + (ROW_COUNT * 2)];
    }

    bool checkTowCrossLines() {
        bool topLeftBottomRightLine = (cells[0] == cells[ROW_COUNT + 1] && cells[0] == cells[NUM_OF_CELLS - 1]);
        bool topRightBottomLeftLine = (cells[ROW_COUNT - 1] == cells[ROW_COUNT + 1] && cells[ROW_COUNT * 2]);
        return topLeftBottomRightLine || topRightBottomLeftLine;
    }

    char check()
    {
        for (int i = 0; i < ROW_COUNT; i++) 
            if (checkRow(i))
                return cells[i]; 
            else if (checkCol(i)) 
                return cells[i];
        
        if (checkTowCrossLines())
            return cells[ROW_COUNT + 1]; 
        return '-'; 
    }

    void result() {
         Player1.printResultIfWin(Player2);
         Player2.printResultIfWin(Player1);
    }
};


int main(int argc, char** argv) {
    BoardGame game;
    
    game.inputRequest();
    game.start();
    game.result();
   
    return 0;
}
