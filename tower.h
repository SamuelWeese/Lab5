#ifndef TOWER_H
#define TOWER_H

#include "towerpiece.h"

class tower
{
public:
    int x, y;
    sf::RectangleShape poleSprite;
    int maxPiece;
    std::vector<towerpiece> towerState;
    tower(int, int = 0, int = 0);
    tower(std::vector<towerpiece>, int = 0, int = 0);
    virtual ~tower() {}
    bool addPiece(towerpiece aPiece);
    towerpiece getTop();
    void removeTop();
    void draw(sf::RenderWindow*);
    void drawSelected(sf::RenderWindow*);
    void setPositioningInitial();

};

#endif // TOWER_H
