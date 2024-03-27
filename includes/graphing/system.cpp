#include "system.h"
#include "constants.h"
#include "graph_info.h"
#include "Graph.h"
#include <iostream>
#include <math.h>

System::System(graph_info *info) : G(info), _info(info)
{
}

void System::Step(int command, graph_info *info)
{
    // check for key clicks and update domain
    if (command == LEFT_KEY)
    {
        info->_domain.x--;
        info->_domain.y--;
    }
    else if (command == RIGHT_KEY)
    {
        info->_domain.x++;
        info->_domain.y++;
    }
    else if (command == UP_KEY)
    {
        // increase 20%
        //[-0.25,0.25] is the limit
        if (info->_domain.y - info->_domain.x > 0.5)
        {
            info->_domain.x += fabs(info->_domain.x) * 0.2;
            info->_domain.y -= fabs(info->_domain.y) * 0.2;
        }
    }
    else if (command == DOWN_KEY)
    {
        // decrease 20%
        //[-30,30] is the limit
        if (info->_domain.y - info->_domain.x < 60.00)
        {
            info->_domain.x -= fabs(info->_domain.x) * 0.2;
            info->_domain.y += fabs(info->_domain.y) * 0.2;
        }
    }
}

void System::Draw(sf::RenderWindow &window, graph_info *info)
{
    // pass draw to graph
    G.Draw(window);
}
