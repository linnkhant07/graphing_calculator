#include <iostream>
#include "coord_translator.h"
#include "constants.h"
#include "../rpn/rpn.h"

using namespace std;

sf::Vector2f COORD_TRANSLATOR::translate(sf::Vector2f graph_coord, sf::Vector2f screen_origin, sf::Vector2f graph_origin)
{
    // graduation = distance between each point
    double graph_graduation = (_info->_domain.y - _info->_domain.x) / (NUM_OF_POINTS - 1);
    double x_graduation = WORK_PANEL / (NUM_OF_POINTS - 1);
    double y_graduation = SCREEN_HEIGHT / (NUM_OF_POINTS - 1);

    // screen_x = screen_origin + graph distance from origin * graduation
    double screen_x = screen_origin.x + ((graph_coord.x - graph_origin.x) / graph_graduation) * x_graduation;
    double screen_y = screen_origin.y + ((graph_origin.y - graph_coord.y) / graph_graduation) * y_graduation;
    sf::Vector2f screen_cord(screen_x, screen_y);

    return screen_cord;
}