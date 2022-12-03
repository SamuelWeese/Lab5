#ifndef GAME_H
#define GAME_H

#include <vector>
#include "tower.h"
#include <string>
#include <error.h>


class game
{
    bool multiPlayer;
    int selectedTower;
    player currentTurn;
    sf::RectangleShape turnIndicator;
    std::vector<tower> gameState;
    bool checkLegality(tower*,tower*);
    bool move();
    int badMove;
    void switchPlayer();
    bool checkWin();
    void changeTurn();
public:
    sf::RenderWindow *aWindow;
    explicit game(sf::RenderWindow*, bool);
    virtual ~game(){}
    void addTower(tower);
    void mouseClick(int x, int y);
    void draw();
};

#endif // GAME_H
