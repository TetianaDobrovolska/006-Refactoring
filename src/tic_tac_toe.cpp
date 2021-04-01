#include <iostream> 
#include <cstring> 
#include <clocale>
#include <stdio.h>
#include <stdlib.h>
#include <regex>

using namespace std;

char win = '-'; 
char PlayerName1[80], PlayerName2[80];
char cells[9] = { '-','-','-','-','-','-','-','-','-' };

void show_cells() {
    system("clear");

    cout << "Cell numbers: \n" << endl;
    cout << "-" << 1 << "-" << "|" << "-" << 2 << "-" << "|" << "-" << 3 << "-" << endl;
    cout << "-" << 4 << "-" << "|" << "-" << 5 << "-" << "|" << "-" << 6 << "-" << endl;
    cout << "-" << 7 << "-" << "|" << "-" << 8 << "-" << "|" << "-" << 9 << "-" << endl;

    cout << "\nCurrent situation (--- empty):\n" << endl;
    cout << "-" << cells[0] << "-" << '|' << "-" << cells[1] << "-" << '|' << "-" << cells[2] << "-" << endl;
    cout << "-" << cells[3] << "-" << '|' << "-" << cells[4] << "-" << '|' << "-" << cells[5] << "-" << endl;
    cout << "-" << cells[6] << "-" << '|' << "-" << cells[7] << "-" << '|' << "-" << cells[8] << "-" << "\n" << endl;

}

void make_move(int num) {
    if (num == 1) cout << PlayerName1;
    else cout << PlayerName2;
    std::string cell;
    cout << ", enter cell number, make your move: ";
    cin >> cell;

    std::regex rx("[1-9]");
    while ((!std::regex_match(cell, rx)) || (cells[stoi(cell) - 1] == 'O') || (cells[stoi(cell) - 1] == 'X')) {
        cout << "Empty shells are marked with (---). \n"
                "Enter the number (1-9) of an empty cell to make a move: ";
        cin >> cell;
        cout << "\n";
    }
    
    if (num == 1) cells[stoi(cell) - 1] = 'X';
    else cells[stoi(cell) - 1] = 'O';
}

char check()
{
    for (int i = 0; i < 3; i++) 
        if ((cells[i * 3] == cells[i * 3 + 1] && cells[i * 3 + 1] == cells[i * 3 + 2]) && cells[i * 3] != '-')
        {
            cout << "Row win" << i+1 << ": " << cells[i * 3] << " " << cells[i * 3 + 1] << " " << cells[i * 3 + 2] << endl;
            return cells[i * 3];
        }
        else if ((cells[i] == cells[i + 3] && cells[i + 3] == cells[i + 6]) && cells[i * 3] != '-')
        {
            cout << "Col win: " << i+1 << ": " << cells[i] << " " << cells[i + 3] << " " << cells[i + 6] << endl;
            return cells[i];
        }
        else if (((cells[2] == cells[4] && cells[4] == cells[6]) || (cells[0] == cells[4] && cells[4] == cells[8])) && cells[i * 3] != '-')
        {
            cout << "Diagonal win: " << cells[2] << " " << cells[4] << " " << cells[6] << endl;
            return cells[4];
        }
    return '-'; 
}

void result() {
    if (win == 'X')
        cout << PlayerName1 << ", you won. Congratulations! " << PlayerName2 << ", you lose..." << endl;
    else if (win == 'O') cout << PlayerName2 << ", you won. Congratulations! " << PlayerName1 << ", you lose..." << endl;

}

int main(int argc, char** argv) {
    system("clear");

    do {
        cout << "Enter the name of the first player: ";
        std::cin >> PlayerName1;

        cout << "Enter the name of the second player: ";
        std::cin >> PlayerName2;
    } while (!strcmp(PlayerName1, PlayerName2));
    
    show_cells();

    for (int move = 1; move <= 9; move++) {
        if (move % 2) make_move(1); 
        else make_move(2);

        show_cells();
        
        if (move >= 5)
        {
            win = check();
            if (win != '-')
                break;
        }
  
    }

    result();
   
    return 0;
}
