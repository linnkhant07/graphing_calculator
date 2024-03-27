#ifndef GRAPH_INFO_H
#define GRAPH_INFO_H
#include <iostream>
#include <string.h>
#include "../queue/MyQueue.h"
#include "../stack/MyStack.h"

#include <vector>

using namespace std;

struct graph_info
{

    graph_info(Queue<string> eq, sf::Vector2f wd, sf::Vector2f origin, sf::Vector2f scale, sf::Vector2f domain) : _window_dimensions(wd), _origin(origin), _scale(scale), _domain(domain)
    {
        _equations = eq;

        drawIndex = _equations.size() - 1;
    }

    Queue<string> _equations;
    sf::Vector2f _window_dimensions;
    sf::Vector2f _origin;
    sf::Vector2f _scale;
    sf::Vector2f _domain;
    int drawIndex;
    int points;
};

#endif