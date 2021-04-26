#include <iostream> 
#include <cstring> 
#include <clocale>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

namespace {

constexpr int kMaxNameSize = kMaxNameSize;
constexpr int kMaxCellCount = 9;
constexpr int kRowSize = 3;
constexpr int kMinStepsToWin = 5;
const char kOSymbol = 'O';
const char kXSymbol = 'X';

}  //namespace

char win = '-'; 
char PlayerName1[kMaxNameSize], PlayerName2[kMaxNameSize];
char cells[kMaxCellCount] = { '-','-','-','-','-','-','-','-','-' };

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

bool isCellValid(const int& cell) {
    return cell > kMaxCellCount || cell < 1 ||
            cells[cell - 1] == kOSymbol ||
            cells[cell - 1] == kXSymbol;
}

void make_move(int num) {
    if (num == 1) cout << PlayerName1;
    else cout << PlayerName2;
    int cell;
    cout << ",enter cell number, make your move:";
    cin >> cell;

    while (!isCellValid(cell)) {
        cout << "Enter the number of the correct (1-9) or empty (---) cells to make a move:";
        cin >> cell;
        cout << "\n";
    }
    
    if (num == 1) cells[cell - 1] = kXSymbol;
    else cells[cell - 1] = kOSymbol;
}

bool isHorizontalLine(const int& index) {
    return cells[index * kRowSize] == cells[index * kRowSize + 1] &&
            cells[index * kRowSize + 1] == cells[index * kRowSize + 2];
}

bool isVerticalLine(const int& index) {
    return cells[index] == cells[index + 3] &&
            cells[index + 3] == cells[index + 6];
}

bool isDiagonalLine() {
    return cells[2] == cells[4] && cells[4] == cells[6] ||
            cells[0] == cells[4] && cells[4] == cells[8];
}

char check()
{
    for (int i = 0; i < 3; i++) 
        if (isHorizontalLine(i) || isVerticalLine(i) || isDiagonalLine())
            return cells[i]; 
    return '-'; 
}

void printResult(const std::string& winer, const std::string loser)
{
    cout << winer << "you won congratulations " << loser << " you lose..." << endl;
}

void result() {
    if (win == kXSymbol)
        printResult(PlayerName1, PlayerName2);
    else if (win == kOSymbol)
        printResult(PlayerName2, PlayerName1);

}

int main(int argc, char** argv) {
    do {
        cout << "Enter the name of the first player: ";
        std::cin >> PlayerName1;

        cout << "Enter the name of the seecond player: ";
        std::cin >> PlayerName2;
    } while (!strcmp(PlayerName1, PlayerName2));
    
    show_cells();

    for (int move = 1; move <= kMaxCellCount; move++) {
        if (move % 2) make_move(1); 
        else make_move(2);

        show_cells();
        
        if (move >= kMinStepsToWin)
        {
            win = check();
            if (win != '-')
                break;
        }
  
    }

    result();
   
    return 0;
}