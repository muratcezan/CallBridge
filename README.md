# CallBridge
## Architecture Diagram
![Tux, the Linux mascot](/assets/Diagram1.png)

- **red :** models
- **lightblue :** constants
- **yellow :** engines
- **green :** print game screen 

## Compile the application
The application tested on Kubuntu 22.04 LTS. So, the developer suggests to use same system.

```
// You should be in project directory
mkdir build
cmake ..
make
```

After that, you will see that compile all classes as shared library for use them with unit tests.

## Game Scenario
Basically, developer tried to make Call Bridge game, but the game has some mistakes because of developer doesn't knows any card games **:)** 

* The game creates with GameEngine and then the GameEngine object gets View class as Inheritance. 
* GameEngine object creates PlayerEngine objects for each player size.
* After that, create a deck and mix.
* Deal mixed cards to all players.
* Players say goal trump number for start game.
* The player with the biggest trick rolls the trump suit and then start the game.
* The player who started the round tries to get as many cards as the target number of trump cards.

## Fun
The game run only 2 or 4 players.

-u PLAYER SIZE

If you run the game without paramters, the game will start with 4 players

```
cd build
./CallBridge
```

or
```
./CallBridge -u 4
```
and
```
./CallBridge -u 2
```