#include <iostream> 
#include <controller.hpp>
#include <stdlib.h>

int main(int argc, char** argv) {
    Controller c;
    while(c.isWin()){
        c.setNames();
        c.makeMove();
    }
    char winner = c.checkWinner();
    std::cout << c.getName(winner) << ", you won congratulations " << std::endl;
    
    return 0;
}