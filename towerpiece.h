#ifndef TOWERPIECE_H
#define TOWERPIECE_H
#include <SFML/Graphics.hpp>

#define SPACING_PX_VERTICAL 50
#define SPACING_PX_HORIZONTAL 30
enum player { red, blue };

class towerpiece
{
public:
    sf::RectangleShape aSprite;
    player owner;
    int size;
    towerpiece();
    towerpiece(player, int);
    virtual ~towerpiece(){}
    void setSprite();

};

#endif // TOWERPIECE_H
