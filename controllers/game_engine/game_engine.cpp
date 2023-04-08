#include <algorithm>
#include <chrono>
#include <random>

#include "game_engine.h"

GameEngine::GameEngine() : playerSize(4)
{
    engine();
}

GameEngine::GameEngine(size_t size) : playerSize(size)
{
    engine();
}

void GameEngine::engine()
{
    tRun = std::thread(&GameEngine::run, this);
    // tPrint = std::thread(&GameEngine::print, this);

    tRun.join();

    // tPrint thread'ini öldürmek için kullanılan kod
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
    }

    while (trumpPlayers.size() != 1)
    {
        for (auto it = std::begin(trumpPlayers); it != std::end(trumpPlayers); ++it)
        {
            auto pe = *it;
            int val = pe.sendTrumpValue();
            if (val == 0)
            {
                trumpPlayers.erase(it);
                break;
            }
            else
            {
                if (val > trumpSize)
                {
                    trumpSize = val;
                }
                else
                {
                    trumpPlayers.erase(it);
                    break;
                }
            }
        }
    }
    // PlayerEngine pe = trumpPlayers.at(0);
    auto pe = *(std::begin(trumpPlayers));
    trump = pe.sendTrumpType();
}

void GameEngine::print()
{
    while (true)
    {
        printMutex.lock();
        clear();
        printUsers(players);
        printDesk(players);
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
