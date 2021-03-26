#include <iostream> 
#include <cstring> 
#include <clocale>
#include <stdio.h>
#include <stdlib.h>
using namespace std;



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
    char cells[9] = { '-','-','-','-','-','-','-','-','-' };

    void inputRequest() {
        char PlayerName1[80], PlayerName2[80];
        do {
            cout << "Enter the name of the first player: ";
            std::cin >> PlayerName1;

            cout << "Enter the name of the seecond player: ";
            std::cin >> PlayerName2;
        } while (!strcmp(PlayerName1, PlayerName2));
    
        Player1.playerName = PlayerName1;
        Player1.chessType = 'X';
        Player1.turn = 1;
        Player2.playerName = PlayerName2;
        Player2.chessType = 'O';
        Player2.turn = 0;
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

        while (cell > 9 || cell < 1 || cells[cell - 1] == 'O' || cells[cell - 1] == 'X') {
            cout << "Enter the number of the correct (1-9) or empty (---) cells to make a move:";
	    cin >> cell;
            cout << "\n";
        }
    
        cells[cell - 1] = player.chessType;
    }

    void start() {
        char win = '-'; 
        show_cells();
        for (int move = 1; move <= 9; move++) {
            checkTurnAndMakeMove(move, Player1);
            checkTurnAndMakeMove(move, Player2);

            show_cells();
        
            if (move >= 5)
            {
                win = check();
                if (win != '-')
                    break;
            }

        }
        Player1.setWinResult(win);
        Player2.setWinResult(win);
    }

    char check()
    {
        for (int i = 0; i < 3; i++) 
            if (cells[i * 3] == cells[i * 3 + 1] && cells[i * 3 + 1] == cells[i * 3 + 2])
                return cells[i]; 
            else if (cells[i] == cells[i + 3] && cells[i + 3] == cells[i + 6]) 
                return cells[i];
            else if ((cells[2] == cells[4] && cells[4] == cells[6]) || (cells[0] == cells[4] && cells[4] == cells[8]))
                return cells[i]; 
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
