#include <algorithm>
#include <chrono>
#include <random>

#include "game_engine.h"

GameEngine::GameEngine() : playerSize(4), trump(Types::Empty), trumpSize(0), gameTour(0)
{
    engine();
}

GameEngine::GameEngine(size_t size) : playerSize(size), trump(Types::Empty), trumpSize(0), gameTour(0)
{
    engine();
}

void GameEngine::engine()
{
    tRun = std::thread(&GameEngine::run, this);
    // tPrint = std::thread(&GameEngine::print, this);

    tRun.join();

    // // tPrint thread'ini öldürmek için kullanılan kod
    // tPrint.detach();
    // while (true)
    // {
    //     if (players.size() == 0)
    //     {
    //         break;
    //     }
    // }
}

void GameEngine::run()
{
    createPlayers();
    shuffleCards(deck.list);
    cardDeal();
    std::vector<PlayerEngine> trumpPlayers;
    for (auto player : players)
    {
        player.engine();
        trumpPlayers.push_back(player);
        std::cout << player.id() << std::endl;
    }

    int tpSize = trumpPlayers.size();

    while (trumpPlayers.size() != 1)
    {
        gameTour++;
        std::vector<PlayerEngine> removePlayers;

        for (auto it = trumpPlayers.begin(); it != trumpPlayers.end(); ++it)
        {

            auto pe = *it;
            int val = pe.sendTrumpValue(trumpSize);
            std::cout << "(*it).id()" << (*it).id() << " TrumpValue = " << val << std::endl;
            if (val == 0)
            {
                removePlayers.push_back(*it);
            }
            else
            {
                if (val > trumpSize)
                {
                    trumpSize = val;
                    playerWon.clear();
                    playerWon.push_back(*it);
                }
                else if (val == trumpSize)
                {
                    playerWon.push_back(*it);
                }
                else
                {
                    continue;
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        trumpPlayers = playerWon;

        std::cout << "----" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    auto pe = *(std::begin(trumpPlayers));
    trump = pe.sendTrumpType();

    if (gameTour > 10)
    {
        std::cerr << "Game couldn't start!" << std::endl;
        exit;
    }
}

void GameEngine::print()
{
    while (true)
    {
        printMutex.lock();
        clear();
        printUsers(players);
        printDesk(players, trump, trumpSize);
        printGetScore(1, players.size());
        printMutex.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void GameEngine::createPlayers()
{
    for (int i = 0; i < playerSize; i++)
    {
        players.push_back(PlayerEngine(i));
    }
}

void GameEngine::cardDeal()
{
    while (deck.list.size() != 0)
    {
        for (int i = 0; i < playerSize; i++)
        {
            players.at(i).getCard(std::move(deck.list.at(0)));
            deck.list.erase(deck.list.begin());
        }
    }
}

void GameEngine::shuffleCards(std::vector<Card *> &list)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::shuffle(list.begin(), list.end(), std::default_random_engine(seed));
}
