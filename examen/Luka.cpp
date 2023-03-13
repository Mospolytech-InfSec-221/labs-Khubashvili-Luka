#include <iostream>
#include "gameKhuba.h"


int main()
{
    std::cout << "Enter player count: ";
    int count;
    std::cin >> count;
    std::cout << "Enter main word: ";
    std::string inputWord;
    std::cin >> inputWord;
    gameKhuba Game1;
    Game1.startGame(count, inputWord);
    Game1.play();
    return 0;
}
