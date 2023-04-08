#pragma once

#include <vector>
#include <vector>

// #include "deck/deck.h"
#include "player_engine/player_engine.h"

// #include "game_engine/game_engine.h"

class GameScreen
{
protected:
    GameScreen();

    void clear();
    void printGameScreen();
    void printUsers(std::vector<PlayerEngine>);
    void printDesk(std::vector<PlayerEngine>);
    void printGetScore(int, int);
    void printBorder(char, int);
    void printTopBorder(size_t);
    void printEmptyLine(size_t);
};