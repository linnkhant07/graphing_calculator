#ifndef SIDEBAR_H
#define SIDEBAR_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include <vector>
#include "textbox.h"
#include "graph_info.h"
#include "../stack/MyStack.h"

using namespace std;

class Sidebar
{
public:
    Sidebar();
    Sidebar(float left, float width, graph_info *info);
    void draw(sf::RenderWindow &window);
    void setFunctions(Queue<string> funcs);
    int isFunctionHover(sf::RenderWindow &window);
    Textbox textbox; // textbox for equation

private:
    sf::RectangleShape rect; // sidebar rectangle
    Queue<string> history;   // display the history functions
    vector<Textbox> functionsDisplay;
    sf::Font font; // used to draw text

    // need graph info for functions queue
    graph_info *_info;

    // the whole history hover panel
    bool isHistoryHover(sf::RenderWindow &window);

    float _left;
    float _width;
    const double BOX_HEIGHT = 70.0;
};

#endif // SIDEBAR_H
