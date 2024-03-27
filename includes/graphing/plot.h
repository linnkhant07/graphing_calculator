#ifndef PLOT_H
#define PLOT_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "graph_info.h"
#include "../queue/MyQueue.h"
#include "../token/token.h"

using namespace std;

class plot
{
public:
    plot(graph_info *gi) : _info(gi) {}
    vector<sf::Vector2f> operator()(); // calculate the graph coordinates
    vector<sf::Vector2f> plot_axis();
    vector<sf::Vector2f> plot_ticks(char axis, int num = 10);

private:
    graph_info *_info;
    Queue<Token *> _post_fix;
    sf::Vector2f _screen_origin;
    sf::Vector2f _graph_origin;
};
#endif