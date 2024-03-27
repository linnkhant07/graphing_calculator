#include "sidebar.h"
#include "constants.h"
#include "../queue/MyQueue.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "miscellanous.h"

using namespace std;

Sidebar::Sidebar()
{
}

Sidebar::Sidebar(float left, float width, graph_info *info) : _left(left), _width(width), _info(info)
{
    cout << "Sidebar CTOR: TOP" << endl;

    // set up the sidebar rectangle:
    rect.setFillColor(sf::Color(192, 192, 192)); //(192,192,192)); //silver
    rect.setPosition(sf::Vector2f(left, 0));
    rect.setSize(sf::Vector2f(width, SCREEN_HEIGHT));
    cout << "Sidebar CTOR: about to load font." << endl;

    if (!font.loadFromFile("Roboto-Thin.ttf"))
    {
        cout << "Sidebar() CTOR: Font failed to load" << endl;
        cin.get();
        exit(-1);
    }
    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    cout << "Sidebar CTOR: loaded font." << endl;

    cout << "Sidebar: CTOR: Exit." << endl;

    // for the text box
    textbox = Textbox(20, sf::Color::Black, sf::Color::White, true, true);
    textbox.setFont(font);
    textbox.setSize(sf::Vector2f(width - 30, 50));
}

void Sidebar::draw(sf::RenderWindow &window)
{
    const double VERTICAL_LINE_SPACING = 7.0;
    const double LEFT_MARGIN = 15.0;

    window.draw(rect);

    float height = 1; // 1-

    textbox.setPosition(sf::Vector2f(_left + LEFT_MARGIN, height + VERTICAL_LINE_SPACING));
    textbox.drawTo(window);

    int index = 0;
    for (Queue<string>::Iterator it = history.begin(); it != history.end(); it++)
    {
        height = textbox.rect().getLocalBounds().height + 30;
        int multiplier = history.size() - 1 - index;
        height += multiplier * BOX_HEIGHT;

        // sf::Color(192, 192, 192)
        Textbox temp(20, sf::Color::Blue, sf::Color(192, 192, 192), true);
        temp.setFont(font);
        temp.setSize(sf::Vector2f(_width, BOX_HEIGHT));
        temp.setPosition(sf::Vector2f(_left, height));
        temp.setText(*it);
        temp.centreText();
        temp.drawTo(window);

        index++;
    }
}

void Sidebar::setFunctions(Queue<string> funcs)
{
    history = funcs;
}

// check if the history panel is hovered
bool Sidebar::isHistoryHover(sf::RenderWindow &window)
{
    // top left coordinates
    float x = _left;
    float y = textbox.rect().getLocalBounds().height + 30;

    float width = _width;
    float height = history.size() * BOX_HEIGHT;
    sf::RectangleShape historyPanel(sf::Vector2f(width, height));
    historyPanel.setPosition({x, y});

    return isHover(window, historyPanel);
}

// check which individual function is hovered
int Sidebar::isFunctionHover(sf::RenderWindow &window)
{
    if (isHistoryHover(window))
    {
        // mouse position y - the input box
        float mousePosition = sf::Mouse::getPosition(window).y;
        float offset = textbox.rect().getLocalBounds().height + 30;

        // below this, it is the space for history
        // divide by the box height to get the box number (index)
        int index = (mousePosition - offset) / BOX_HEIGHT;

        // need to adjust since the boxes are upside down
        int fixedIndex = history.size() - 1 - index;
        return fixedIndex;
    }

    return -1;
}