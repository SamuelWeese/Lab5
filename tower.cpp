#include "tower.h"

tower::tower(int aInt, int x, int y)
{
    maxPiece = aInt;
    this->x = x;
    this->y = y;
}

tower::tower(std::vector<towerpiece> aTower, int x, int y)
{
    this->towerState = aTower;
    this->maxPiece = towerState.size();
    this->x = x;
    this->y = y;
}

bool tower::addPiece(towerpiece aPiece)
{
    //if (this->getTop().size > aPiece.size) return false;
    towerState.push_back(aPiece);
    setPositioningInitial();
    return true;
}

towerpiece tower::getTop()
{
    if (towerState.size() < 1)
    {
        return towerpiece(red, -1);
    }
    return towerState[towerState.size()-1];
}

void tower::removeTop()
{
    if (towerState.size() < 1)
    {
        return;
    }
    towerState.pop_back();
}

void tower::draw(sf::RenderWindow *aWindow)
{
    aWindow->draw(poleSprite);
    for (long iterI = 0; iterI < towerState.size(); iterI++)
    {
        aWindow->draw(towerState[iterI].aSprite);
    }
}

void tower::drawSelected(sf::RenderWindow *aWindow)
{
    aWindow->draw(poleSprite);
    sf::RectangleShape cover = poleSprite;
    cover.setFillColor(sf::Color(0,255,0,255));
    aWindow->draw(cover);
    for (long iterI = 0; iterI < towerState.size(); iterI++)
    {
        aWindow->draw(towerState[iterI].aSprite);
    }
    if (towerState.size() < 1) return;
    cover = towerState[towerState.size()-1].aSprite;
    cover.setFillColor(sf::Color(255,255,255,190));
    aWindow->draw(cover);
}

void tower::setPositioningInitial()
{
    this->poleSprite.setFillColor(sf::Color::White);
    this->poleSprite.setSize(sf::Vector2f(SPACING_PX_HORIZONTAL/2.f, (float)maxPiece*(SPACING_PX_VERTICAL)));
    this->poleSprite.setPosition(x, y+SPACING_PX_VERTICAL*2.0f);
    for (long iterI = 0; iterI < towerState.size(); iterI++)
    {
        towerState[iterI].aSprite.setPosition(x-((towerState[iterI].aSprite.getSize().x-SPACING_PX_HORIZONTAL/2.f)/2.f), (float)maxPiece*(SPACING_PX_VERTICAL*1.1)-((float)iterI*SPACING_PX_HORIZONTAL*1.05f));
    }

}

