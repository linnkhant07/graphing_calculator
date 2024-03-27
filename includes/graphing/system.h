#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <SFML/Graphics.hpp>

#include "graph_info.h"
#include "Graph.h"
#include "plot.h"

using namespace std;
class System
{
public:
    System(graph_info *info);
    void Step(int command, graph_info *info); // new
    void Draw(sf::RenderWindow &widnow, graph_info *info);

private:
    graph_info *_info;
    Graph G;
};

#endif // SYSTEM_H
