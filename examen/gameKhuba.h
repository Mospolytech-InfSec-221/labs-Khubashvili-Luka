#pragma once

#include <string>
#include <algorithm>
#include <unordered_set>
#include <iostream>

class gameKhuba
{
public:
    gameKhuba();
    ~gameKhuba();
    void startGame(int count, std::string inputWord);
    void play();
   
private:
    std::string sourceWord;
    int* players;
    int* points;
    int playerCount;
    int currentStep;
    std::unordered_set<std::string> usedWords;
    bool makeMove(std::string word);
};


