#include <iostream>
#include "textbox.h"
#include <string.h>
#include "miscellanous.h"
#include <SFML/Graphics.hpp>

using namespace std;

Textbox::Textbox(int size, sf::Color color, sf::Color bgColor, bool sel, bool isInput) : isInputBox(isInput)
{
    displayText.setCharacterSize(size);
    displayText.setFillColor(color);
    displayText.setStyle(sf::Text::Bold);
    box.setFillColor(bgColor);
    isSelected = sel;
    // set to DISPLAY TEXT not TEXT
    displayText.setString("_");
}

// you need to create font and pass it by value
void Textbox::setFont(sf::Font &f)
{
    displayText.setFont(f);
}

// in case you want to change position
void Textbox::setPosition(sf::Vector2f pos)
{
    box.setPosition(pos);
    displayText.setPosition(pos);
}
// check if the textbox is selected
void Textbox::setSelected(bool sel)
{
    isSelected = sel;
}

void Textbox::setText(string t)
{
    text = t;
}

// return text to get the equation
string Textbox::getText()
{
    return text;
}

// set size
void Textbox::setSize(sf::Vector2f size)
{
    box.setSize(size);
}

// draw the displaytext to window
void Textbox::drawTo(sf::RenderWindow &window)
{
    if (isSelected && isInputBox)
        displayText.setString(text + "_");
    else
        displayText.setString(text);
    window.draw(box);
    window.draw(displayText);
}

sf::RectangleShape &Textbox::rect()
{
    return box;
}

// the conditional messes will be taken care of here
void Textbox::typedOn(sf::Event input)
{
    if (isSelected)
    {
        // because the input is in unicode
        int charTyped = input.text.unicode;

        if (charTyped < 128)
        {
            charInput(charTyped);
        }
    }
}

bool Textbox::isSelect()
{
    return isSelected;
}

bool Textbox::isBoxHover(sf::RenderWindow &window)
{
    return isHover(window, box);
}

void Textbox::charInput(int charTyped)
{
    if (charTyped != DELETE)
    {
        // append to the string
        text += charTyped;
    }

    else if (charTyped == DELETE)
    {

        if (text.length() > 0)
        {
            // remove the last element
            text.pop_back();
        }
    }
}

void Textbox::centreText()
{
    // to make the text center-align
    sf::Vector2f pos = box.getPosition();
    float xPos = ((pos.x + box.getGlobalBounds().width / 4) - (displayText.getGlobalBounds().width / 2));
    float yPos = ((pos.y + box.getGlobalBounds().height / 4) - (displayText.getGlobalBounds().height / 2)) - 5;
    displayText.setPosition(sf::Vector2f(xPos, yPos));
}