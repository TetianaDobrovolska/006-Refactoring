#include <iostream> 
#include <cstring> 
#include <clocale>
#include <stdio.h>
#include <stdlib.h>
#include "tic_tac_toe.h"
using namespace std;

int main(int argc, char** argv) {
    TicTacToe t("pl1", "pl2", cin, cout);
	t.play_game();

    return 0;
}