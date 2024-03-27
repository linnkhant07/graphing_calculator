#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>

using namespace std;

bool isHover(sf::RenderWindow &window, sf::RectangleShape shape)
{
    // get position of mouse
    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;

    // btn position
    float btnPosX = shape.getPosition().x;
    float btnPosY = shape.getPosition().y;

    // the domain of the shape
    float btnxPosWidth = shape.getPosition().x + shape.getGlobalBounds().width;
    float btnyPosHeight = shape.getPosition().y + shape.getGlobalBounds().height;

    // if mouse is in the domain of the btn
    if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY)
    {
        return true;
    }

    return false;
}

bool double_equals(double left, double right)
{
    return fabs(left - right) < 0.000000001;
}