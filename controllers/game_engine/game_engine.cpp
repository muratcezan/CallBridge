#include <algorithm>
#include <chrono>
#include <random>
#include <queue>

#include "game_engine.h"

//////////////////////////////////////////////////////////
/// @brief Constructer for the game with players size
GameEngine::GameEngine() : playerSize(4), trump(Types::Empty), trumpSize(0), gameTour(0)
{
    engine();
}

//////////////////////////////////////////////////////////
/// @brief Constructer for the game with players size
/// @param size
GameEngine::GameEngine(size_t size) : playerSize(size), trump(Types::Empty), trumpSize(0), gameTour(0)
{
    engine();
}

//////////////////////////////////////////////////////////
/// @brief Run game threads
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
//////////////////////////////////////////////////////////
/// @brief Engine run
void GameEngine::run()
{
    createPlayers();
    shuffleCards(deck.list);
    cardDeal();
    selectTrump();
    // updateQueue(players, startPlayer);

    // std::vector<Score> *sc = new std::vector<Score>;

    for (auto player : players)
    {
        std::cout << "ID = " << player.id() << "TrumpSize = " << player.trumpSize << std::endl;
    }

    // while (scoreList.size() != startPlayer.player_deck.size())
    // {
    //     Score sc;
    //     bool isFirstCard;
    //     for (auto it = std::begin(players); it != std::end(players); ++it)
    //     {
    //         if (sc.scoreHistory.size() == 0)
    //         {
    //             sc.scoreHistory.push_back((*it).selectCard(trump, true));
    //             continue;
    //         }
    //         else
    //         {
    //             auto bigCard = findMaxCard(sc.scoreHistory);
    //         }
    //     }
    //     // std::cout << 1 << std::endl;
    //     // scoreList.push_back(Score())
    // }
}

//////////////////////////////////////////////////////////
/// @brief Engine wants trump size and trump from every player and set
///         them for the game
void GameEngine::selectTrump()
{
    for (auto player : players)
    {
        player.selectTrump();
        std::cout << "player.importantCardSize = " << player.trumpSize << std::endl;
    }
    // // KOZ SECIMI
    // std::vector<PlayerEngine> trumpPlayers;
    // for (auto player : players)
    // {
    //     player.engine();
    //     trumpPlayers.push_back(player);
    //     std::cout << player.id() << std::endl;
    // }

    // int tpSize = trumpPlayers.size();

    // while (trumpPlayers.size() != 1)
    // {
    //     gameTour++;
    //     std::vector<PlayerEngine> removePlayers;

    //     for (auto it = trumpPlayers.begin(); it != trumpPlayers.end(); ++it)
    //     {

    //         auto pe = *it;
    //         int val = pe.sendTrumpValue(trumpSize);

    //         if (val == 0)
    //         {
    //             removePlayers.push_back(*it);
    //         }
    //         else
    //         {
    //             if (val > trumpSize)
    //             {
    //                 trumpSize = val;
    //                 playerWon.clear();
    //                 playerWon.push_back(*it);
    //             }
    //             else if (val == trumpSize)
    //             {
    //                 playerWon.push_back(*it);
    //             }
    //             else
    //             {
    //                 continue;
    //             }
    //         }
    //         std::this_thread::sleep_for(std::chrono::milliseconds(500));
    //     }
    //     trumpPlayers = playerWon;

    //     std::this_thread::sleep_for(std::chrono::milliseconds(500));
    // }
    // auto pe = *(std::begin(trumpPlayers));
    // trump = pe.sendTrumpType();

    // if (gameTour > 10)
    // {
    //     std::cerr << "Game couldn't start!" << std::endl;
    //     exit;
    // }

    // // auto pl = std::next(trumpPlayers.begin(), 0);
    // startPlayer = *trumpPlayers.begin();
    // trumpPlayers.clear();
}

Card *GameEngine::findMaxCard(const std::vector<Card *> &scoreHistory)
{
    if (scoreHistory.empty())
    {
        return nullptr;
    }

    // Card *maxCard = scoreHistory.front();
    // for (const auto &card : scoreHistory)
    // {
    //     if (*card > *maxCard)
    //     {
    //         maxCard = card;
    //     }
    // }

    return nullptr;
}

//////////////////////////////////////////////////////////
/// @brief Update tour queue
/// @param players game players
/// @param startPlayer who will start the tour
void GameEngine::updateQueue(std::vector<PlayerEngine> &players, PlayerEngine &startPlayer)
{
    for (int index = 0; index < players.size(); index++)
    {
        auto nextPlayer = players.begin();

        if ((*nextPlayer).id() != startPlayer.id())
        {
            std::rotate(std::begin(players), std::begin(players) + 1, std::end(players));
        }
        else
        {
            break;
        }
    }
}

//////////////////////////////////////////////////////////
/// @brief Print game screen
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
//////////////////////////////////////////////////////////
/// @brief GameEngine creates players
void GameEngine::createPlayers()
{
    for (int i = 0; i < playerSize; i++)
    {
        players.push_back(PlayerEngine(i));
    }
}

//////////////////////////////////////////////////////////
/// @brief Engine deals mixed cards to players
void GameEngine::cardDeal()
{
    while (deck.list.size() != 0)
    {
        for (int i = 0; i < playerSize; i++)
        {
            players.at(i).addCardToDeck(std::move(deck.list.at(0)));
            deck.list.erase(deck.list.begin());
        }
    }
}

//////////////////////////////////////////////////////////
/// @brief Shuffle cards in the deck
/// @param list
void GameEngine::shuffleCards(std::vector<Card *> &list)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::shuffle(list.begin(), list.end(), std::default_random_engine(seed));
}
