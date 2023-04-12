#pragma once

#include <iostream>
#include <thread>
#include <mutex>

#include "deck/deck.h"
#include "game_screen.h"
#include "player_engine/player_engine.h"

class GameEngine : public GameScreen
{
public:
    GameEngine();
    GameEngine(size_t);

    std::thread tRun;
    std::thread tPrint;

    Types trump;
    int trumpSize;
    Deck deck;

    void engine();
    void run();
    void print();
    void cardDeal();
    void shuffleCards(std::vector<Card *> &);
    void selectTrump();
    void createPlayers();
    void updateQueue(std::vector<PlayerEngine> &, PlayerEngine &);
    Card *findMaxCard(const std::vector<Card *> &scoreHistory);

    std::vector<PlayerEngine> players;
    std::vector<PlayerEngine> playerWon;
    PlayerEngine startPlayer;

    std::vector<Score> scoreList;

    size_t playerSize;
    std::mutex printMutex; // mutex tanımlama
    int gameTour;
};
