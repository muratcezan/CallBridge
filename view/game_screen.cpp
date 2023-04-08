#include <functional>
#include <iostream>

#include "game_screen.h"

GameScreen::GameScreen()
{
    clear();
}

void GameScreen::clear()
{
#if defined _WIN32
    system("cls");
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined(__APPLE__)
    system("clear");
#endif
}

void GameScreen::printGameScreen()
{
    clear();
    // printUsers(gEngine.players);
    // printDesk(desk.players);
    // printGetScore(0, desk.players.size());
}

void GameScreen::printUsers(std::vector<PlayerEngine> players)
{
    printTopBorder(players.size());
    printEmptyLine(players.size());
    printEmptyLine(players.size());

    for (auto player : players)
    {
        std::cout << "| \t \t USER ID = " << player.id() << "\t \t";
    }
    std::cout << "|" << std::endl;
    for (auto player : players)
    {
        std::cout << "| \t \t CARDS = " << player.player_deck.size() << "\t \t";
    }
    std::cout << "|" << std::endl;
    for (auto player : players)
    {
        std::cout << "| \t \t SCORE = " << player.scores.size() << "\t \t";
    }
    std::cout << "|" << std::endl;

    printEmptyLine(players.size());
    printTopBorder(players.size());
}

void GameScreen::printDesk(std::vector<PlayerEngine> players)
{
    std::function<int()> tabSize = [players]
    {
        if (players.size() == 4)
        {
            return 10;
        }
        else
        {
            return 5;
        }
    };
    printEmptyLine(players.size());
    printBorder('|', 1);
    printBorder('\t', tabSize());
    std::cout << "DESK";
    printBorder('\t', tabSize());
    printBorder('|', 1);
    std::cout << std::endl;

    printEmptyLine(players.size());
    printBorder('|', 1);
    printBorder('\t', tabSize() - 2);
    std::cout << "TRUMP = ";
    printBorder('\t', tabSize() + 1);
    printBorder('|', 1);
    std::cout << std::endl;

    printBorder('|', 1);
    printBorder('\t', tabSize() - 3);
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++";
    printBorder('\t', tabSize() - 2);
    printBorder('|', 1);
    std::cout << std::endl;

    for (auto player : players)
    {
        std::cout << "| \t \t USER ID = " << player.id() << "\t \t";
    }
    std::cout << "|" << std::endl;

    for (auto player : players)
    {
        std::cout << "| \t \t OPEN = Heart - 5 \t";
    }
    std::cout << "|" << std::endl;
    printEmptyLine(players.size());
    printTopBorder(players.size());
}

void GameScreen::printGetScore(int playerID, int size)
{
    std::function<int()> tabSize = [size]
    {
        if (size == 4)
        {
            return 9;
        }
        else
        {
            return 4;
        }
    };
    printEmptyLine(size);
    printEmptyLine(size);
    printBorder('|', 1);
    printBorder('\t', tabSize());
    std::cout << "GET SCORE!";
    printBorder('\t', tabSize() + 1);
    printBorder('|', 1);
    std::cout << std::endl;

    printBorder('|', 1);
    printBorder('\t', tabSize());
    std::cout << "USER ID = ";
    std::cout << playerID;
    printBorder('\t', tabSize() + 1);
    printBorder('|', 1);
    std::cout << std::endl;
    printEmptyLine(size);
    printEmptyLine(size);
    printTopBorder(size);
}

void GameScreen::printBorder(char c, int repeat)
{
    for (int i = 0; i < repeat; i++)
    {
        std::cout << c;
    }
}

void GameScreen::printTopBorder(size_t size)
{
    if (size == 4)
        printBorder('-', 162);
    else
        printBorder('-', 81);

    std::cout << std::endl;
}

void GameScreen::printEmptyLine(size_t size)
{
    std::cout << "|";
    if (size == 4)
        printBorder('\t', 20);
    else
        printBorder('\t', 10);
    std::cout << "|" << std::endl;
}
