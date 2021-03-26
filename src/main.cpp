#include "tic_tac_toe.h"

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char** argv)
{
    do {
        cout << "Enter the name of the first player: ";
        std::cin >> PlayerName1;

        cout << "Enter the name of the seecond player: ";
        std::cin >> PlayerName2;
    } while (!strcmp(PlayerName1, PlayerName2));

    show_cells();

    for (int move = 1; move <= 9; move++) {
        make_move((move % 2) ? 1 : 2);

        show_cells();

        if (move >= 5) {
            win = check();
            if (win != '-')
                break;
        }
    }

    result();

    return 0;
}
