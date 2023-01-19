#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

class player {
public:
    std::string name;
    int gold;
    int wood;
    int tokens;
    int cube1;
    int cube2;
    int cube3;
    int additionalCube;
    bool hasAnAdviser;
    int militaryRegister;
    int victoryPoints;
    std::vector<std::string> buildings;
};

class adviser {
public:
    std::string name;
    std::string playerName;
};

class Game_Surname {
public:
    std::vector<player> players;
    std::vector<adviser> advisers;
    int year;
    int stage;
    std::string enemy;
    void stage1();
    void stage2();
    void stage3();
    void stage4();
    void stage5();
    void stage6();
    void stage7();
    void stage8();
    void applyBattleResults(player& player, int battleResult, std::vector<adviser>& advisers, int year, std::string enemy);
    void start();
};

void Game_Surname::start() {
    stage1();
    stage3();
    stage5();
    stage6();
}

void Game_Surname::stage1() {
    std::cout << "stage 1: Initialization" << std::endl;
    std::cout << "Enter number of players: ";
    int numPlayers;
    std::cin >> numPlayers;

    for (int i = 0; i < numPlayers; i++) {
        player Khubashvili_kinsburg;
        std::cout << "Enter player " << i + 1 << " name: ";
        std::cin >> kishiev_kinsburg.name;
        Khubashvili_kinsburg.gold = 5;
        Khubashvili_kinsburg.wood = 5;
        Khubashvili_kinsburg.tokens = 5;
        Khubashvili_kinsburg.cube1 = 0;
        Khubashvili_kinsburg.cube2 = 0;
        Khubashvili_kinsburg.cube3 = 0;
        Khubashvili_kinsburg.hasAnAdviser = false;
        Khubashvili_kinsburg.additionalCube = 0;
        Khubashvili_kinsburg.militaryRegister = 0;
        Khubashvili_kinsburg.victoryPoints = 0;
        players.push_back(Khubashvili_kinsburg);
    }
}