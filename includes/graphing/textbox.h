#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string.h>
#include "constants.h"

using namespace std;

class Textbox
{

public:
    Textbox() {}

    Textbox(int size, sf::Color color, sf::Color bgColor, bool sel = false, bool isInput = false);

    // you need to create font and pass it by value
    void setFont(sf::Font &f);

    // in case you want to change position
    void setPosition(sf::Vector2f pos);

    // check if the textbox is selected
    void setSelected(bool sel);

    void setText(string t);

    // return text to get the equation
    string getText();

    // set size
    void setSize(sf::Vector2f size);

    // draw the displaytext to window
    void drawTo(sf::RenderWindow &window);

    sf::RectangleShape &rect();

    // the conditional messes will be taken care of here
    void typedOn(sf::Event input);

    // check if this textbox is selected
    bool isSelect();

    // check if this textbox is being hovered
    bool isBoxHover(sf::RenderWindow &window);

    // center the text
    void centreText();

    sf::FloatRect getLocalBounds()
    {
        return box.getLocalBounds();
    }

private:
    sf::Text displayText;
    string text;
    sf::RectangleShape box;
    bool isSelected = false;
    bool isInputBox;

    void charInput(int charTyped);
};

#endif