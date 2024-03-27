#ifndef COORD_TRANSLATOR_H
#define COORD_TRANSLATOR_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "graph_info.h"

using namespace std;

class COORD_TRANSLATOR
{
public:
    COORD_TRANSLATOR(graph_info *info) : _info(info) {}
    sf::Vector2f translate(sf::Vector2f graph_coord, sf::Vector2f screen_origin, sf::Vector2f graph_origin);

private:
    graph_info *_info;
};

#endif