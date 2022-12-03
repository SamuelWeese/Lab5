#include "towerpiece.h"

towerpiece::towerpiece()
{
    this->size = -1;
    this->owner = red;
}

towerpiece::towerpiece(player aPlayer, int aSize)
{
    this->size = aSize;
    this->owner = aPlayer;
    setSprite();
}

void towerpiece::setSprite()
{
    if (this->size < 0)
    {
        aSprite.setFillColor(sf::Color::Magenta);
        return;
    }
    aSprite.setSize(sf::Vector2f(size*SPACING_PX_HORIZONTAL*0.9f, SPACING_PX_VERTICAL*0.5f));
    if (owner == red) aSprite.setFillColor(sf::Color::Red);
    if (owner == blue) aSprite.setFillColor(sf::Color::Blue);
}
