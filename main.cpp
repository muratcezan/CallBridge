#include <string>

#include "game_engine/game_engine.h"

int main(int argc, char *argv[])
{
    int playerSize = 4;

    if (argc >= 2)
    {
        if (std::string(argv[1]) == std::string("-u"))
        {
            if (argc == 2)
            {
                std::cerr << "[!] Forgot player size! \n Please input that as 2 or 4!" << std::endl;
                exit(0);
            }
            std::string val = std::string(argv[2]);
            if (stoi(val) == 2 || stoi(val) == 4)
            {
                playerSize = stoi(val);
            }
            else
            {
                std::cerr << "[!] Wrong player size! Only parameters work 2 or 4!" << std::endl;
                exit(0);
            }
        }
        else
        {
            std::cerr << "[!] Wrong parameter! Please use `-u`" << std::endl;
            exit(0);
        }
    }

    GameEngine engine(playerSize);

    return 0;
}