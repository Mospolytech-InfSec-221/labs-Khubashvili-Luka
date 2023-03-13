#include "gameKhuba.h"


gameKhuba::gameKhuba()
{

}

gameKhuba::~gameKhuba()
{
    delete[] players;
    delete[] points;
}

void gameKhuba::startGame(int count, std::string inputWord) {
    this->sourceWord = inputWord;
    this->playerCount = count;
    this->currentStep = 0;

    this->points = new int[count];
    for (int i = 0; i < count; i++) {
        points[i] = 0;
    }

    this->players = new int[count];
    
}

void gameKhuba::play() {
    std::cout << "Starting game with word: " << sourceWord << std::endl;
    while (true) {
        std::cout << "Player " << currentStep + 1 << " enter your word: ";
        std::string word;
        std::cin >> word;
        if (word == "0") {
            break;
        }
        if (!makeMove(word)) {
            std::cout << "Word already user" << std::endl;
        }
    }
    std::cout << "Game over! Final scores:" << std::endl;
    for (int i = 0; i < playerCount; i++) {
        std::cout << "Player " << i + 1 << ": " << points[i] << " points" << std::endl;
    }
}


bool gameKhuba::makeMove(std::string word) {
    std::string tempWord = this->sourceWord;
    for (char c : word) {
        if (std::count(tempWord.begin(), tempWord.end(), c) == 0) {
            return false;
        }
        tempWord.erase(std::find(tempWord.begin(), tempWord.end(), c));
        //erase удаляет символ с из строки
    }

    if (usedWords.count(word) > 0) {
        return false;
    }

    usedWords.insert(word);
    points[currentStep]++;
    currentStep++;

    if (currentStep >= playerCount) {
        currentStep = 0;
    }

    return true;
}

