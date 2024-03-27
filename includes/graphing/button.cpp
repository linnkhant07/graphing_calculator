#include <iostream>
#include "button.h"
#include <SFML/Graphics.hpp>
#include <string.h>

using namespace std;

Button::Button(string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor)
{
    text.setString(t);
    text.setFillColor(textColor);
    text.setCharacterSize(charSize);

    button.setSize(size);
    button.setFillColor(bgColor);
}

void Button::setFont(sf::Font &font)
{
    text.setFont(font);
}

void Button::setBackColor(sf::Color color)
{
    button.setFillColor(color);
}

void Button::setTextColor(sf::Color color)
{
    text.setFillColor(color);
}

void Button::setPosition(sf::Vector2f pos)
{
    button.setPosition(pos);

    // to make the text center-align
    float xPos = ((pos.x + button.getGlobalBounds().width / 2) - (text.getGlobalBounds().width / 2));
    float yPos = ((pos.y + button.getGlobalBounds().height / 2) - (text.getGlobalBounds().height / 2)) - 5;
    text.setPosition(sf::Vector2f(xPos, yPos));
}

// check if mouse is in the area of the button
bool Button::isMouseOver(sf::RenderWindow &window)
{
    return isHover(window, button);
}

// draw the rectangle and string separately
// we can't just draw the whole button bro
void Button::drawTo(sf::RenderWindow &window)
{
    window.draw(button);
    window.draw(text);
}

void Button::setOrigin(sf::Vector2f origin)
{
    button.setOrigin(origin);
    text.setOrigin(origin);
}

sf::FloatRect Button::getGlobalBounds()
{
    return button.getGlobalBounds();
}
void Button::setBold()
{
    text.setStyle(sf::Text::Bold);
}