#ifndef HELP_H
#define HELP_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "button.h"

using namespace std;

class Help
{
public:
    Help();

    void show(sf::RenderWindow &window); // hide - show the help page

    void drawSmallIcon(sf::RenderWindow &window); // draw ? icon

    bool isButtonsHover(sf::RenderWindow &window); // check if ? or X is pressed

    void toggleHelp() { isBoxVisible = !isBoxVisible; } // toggle the visibility of the help box

private:
    sf::Font font;
    sf::Text text;
    sf::RectangleShape background;
    Button btn_close;
    Button btn_icon;
    bool isBoxVisible = false;
};

#endif