#include "game.h"

#include <SFML/Window/Mouse.hpp>
game::game(sf::RenderWindow *aWindow, bool multiPlayer)
{
    this->aWindow = aWindow;
    this->selectedTower = -1;
    this->badMove = 0;
    currentTurn = blue;
    this->multiPlayer = multiPlayer;
    if (multiPlayer){
    this->turnIndicator.setSize(sf::Vector2f(100,100));
    this->turnIndicator.setFillColor(sf::Color::Blue);
    this->turnIndicator.setPosition(sf::Vector2f(aWindow->getSize().x-100, aWindow->getSize().y-100));
    }
}

void game::addTower(tower aTower)
{
    int x = 100;
    for (long iterI = 0; iterI < gameState.size(); iterI++)
    {
        x += SPACING_PX_VERTICAL*gameState[iterI].maxPiece/1.5f;
    }
    gameState.push_back(aTower);
    gameState[gameState.size()-1].x = x;
    gameState[gameState.size()-1].y = 50;
    gameState[gameState.size()-1].setPositioningInitial();
}
bool game::checkLegality(tower *a, tower *b)
{
    if (b->maxPiece == b->towerState.size())
    {
        return false;
    }
    if (a->getTop().size < 1) return false;
    if (b->getTop().size < a->getTop().size && b->getTop().size != -1) return false;
    b->addPiece(a->getTop());
    a->removeTop();
    return true;

}
//void badMove();
//void switchPlayer();
void game::mouseClick(int x, int y)
{
    for (long iterI = 0; iterI < gameState.size(); iterI++)
    {
        if (gameState[iterI].x - x < 50 && gameState[iterI].x - x > -50)
        {
            if ((gameState[iterI].getTop().owner != currentTurn && gameState[iterI].getTop().size != -1 && selectedTower == -1))
            {
                badMove = 255;
                selectedTower = -1;
                return;
            }
            if (selectedTower == -1)
            {
                selectedTower = iterI;
                return;
            }
            if (checkLegality(&gameState[selectedTower], &gameState[iterI]))
            {
                selectedTower = -1;
                if (this->multiPlayer)
                    changeTurn();
            }
            else
            {
                badMove = 255;
                selectedTower = -1;
                return;
            }
        }
    }
    return;
}
void game::draw()
{
    if (badMove)
    {
        badMove--;
        aWindow->clear(sf::Color(badMove, 0, 0, 0));
    }
    aWindow->draw(turnIndicator);
    for (int iterI = 0; iterI < gameState.size(); iterI++)
    {
        if (iterI == selectedTower)
        {
            gameState[selectedTower].drawSelected(aWindow);
            continue;
        }
        gameState[iterI].draw(aWindow);
    }
}
void game::changeTurn()
{
    if (currentTurn == red)
    {
        currentTurn = blue;
        this->turnIndicator.setFillColor(sf::Color::Blue);
    }
    else {
        currentTurn = red;
        this->turnIndicator.setFillColor(sf::Color::Red);
    }
}

