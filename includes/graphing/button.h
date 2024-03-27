#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string.h>
#include "miscellanous.h"

using namespace std;

class Button
{
public:
    Button() {}

    Button(string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor);

    // these functions set attributes to text or button
    void setFont(sf::Font &font);

    void setBackColor(sf::Color color);

    void setTextColor(sf::Color color);

    void setPosition(sf::Vector2f pos);

    void setOrigin(sf::Vector2f origin);

    sf::FloatRect getGlobalBounds();

    void setBold();

    sf::Vector2f getSize() { return button.getSize(); }

    // check if mouse is in the area of the button
    bool isMouseOver(sf::RenderWindow &window);

    void drawTo(sf::RenderWindow &window);

private:
    sf::RectangleShape button;
    sf::Text text;
};

#endif