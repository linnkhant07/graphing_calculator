#include "plot.h"
#include "../token/tokenizer.h"
#include "../rpn/rpn.h"
#include "constants.h"
#include "../shunting_yard/shunting_yard.h"
#include "miscellanous.h"
#include "coord_translator.h"
#include "../queue/MyQueue.h"
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

vector<sf::Vector2f> plot::operator()()
{
    // delta x
    double delta_x = (_info->_domain.y - _info->_domain.x) / (NUM_OF_POINTS - 1);

    // check which index to draw
    Queue<string>::Iterator it = _info->_equations.begin();
    for (int i = 0; i < _info->drawIndex; i++)
    {
        it++;
    }
    // the equation at that index
    string equation = *it;

    // tokenize the equation
    Tokenizer tokenizer(equation);
    Queue<Token *> infix = tokenizer.tokenize();

    // shunting yard
    ShuntingYard sy(infix);
    _post_fix = sy.postfix();

    // rpn the postfix
    RPN rpn(_post_fix);

    // origins
    _screen_origin = sf::Vector2f(WORK_PANEL / 2, SCREEN_HEIGHT / 2);
    double origin_x = (_info->_domain.y + _info->_domain.x) / 2;
    double origin_y = 0;

    _graph_origin = sf::Vector2f(origin_x, origin_y);

    // graph coordinates
    vector<sf::Vector2f> graph_coordinates;

    // screen coordinates
    vector<sf::Vector2f> screen_coordinates;

    // translator
    COORD_TRANSLATOR translator(_info);

    // loop and fill the graph_coordinates
    for (double i = _info->_domain.x; !double_equals(i, _info->_domain.y); i += delta_x)
    {
        double y = rpn(i);
        if (isnan(y))
            continue;
        // the single point
        sf::Vector2f single_cord(i, y);
        // graph_coordinates.push_back(single_cord);

        // cout << "x is now " << i << endl;
        // cout << "y is now " << y << endl;
        graph_coordinates.push_back(translator.translate(single_cord, _screen_origin, _graph_origin));
    }
    // cout << _info->_equations << endl;
    return graph_coordinates;
}

// do this after getting curve points
vector<sf::Vector2f> plot::plot_axis()
{
    // delta x
    double delta_x = (_info->_domain.y - _info->_domain.x) / (NUM_OF_POINTS - 1);

    // translator
    COORD_TRANSLATOR translator(_info);

    // origins
    _screen_origin = sf::Vector2f(WORK_PANEL / 2, SCREEN_HEIGHT / 2);
    double origin_x = (_info->_domain.y + _info->_domain.x) / 2;
    double origin_y = 0;

    _graph_origin = sf::Vector2f(origin_x, origin_y);

    // axis on graph
    vector<sf::Vector2f> axis;

    // for x-axis
    for (double i = _info->_domain.x; i <= _info->_domain.y; i += delta_x)
    {
        sf::Vector2f single_cord(i, 0);
        axis.push_back(translator.translate(single_cord, _screen_origin, _graph_origin));
    }

    // for y-axis
    // to calculate how much of y on each side of x-axis
    double length = (_info->_domain.y - _info->_domain.x) / 2;

    for (double i = -length; i <= length; i += delta_x)
    {
        sf::Vector2f single_cord(0, i);
        axis.push_back(translator.translate(single_cord, _screen_origin, _graph_origin));
    }

    return axis;
}

vector<sf::Vector2f> plot::plot_ticks(char axis, int num)
{
    // num presents the amount of ticks you want on the axis
    float graduation = (_info->_domain.y - _info->_domain.x) / num;
    // cout << "graduation is " << graduation << endl;

    vector<sf::Vector2f> screen_cords;
    sf::Vector2f single_cord;

    // origins
    _screen_origin = sf::Vector2f(WORK_PANEL / 2, SCREEN_HEIGHT / 2);
    double origin_x = (_info->_domain.y + _info->_domain.x) / 2;
    double origin_y = 0;

    _graph_origin = sf::Vector2f(origin_x, origin_y);

    for (int i = 0; i < num + 1; i++)
    {
        // graph cords
        if (axis == 'x')
        {
        }
        single_cord.x = _info->_domain.x + (i * graduation);
        single_cord.y = 0;

        if (fabs(single_cord.x) < 0.0001)
        {
            // meaning it's 0
            // then don't draw!!
            continue;
        }

        /*
        cout << "x is " << single_cord.x << endl;
        cout << "y is " << single_cord.y << endl;
        */
        // change it to screen cord
        //  translator
        COORD_TRANSLATOR translator(_info);
        screen_cords.push_back(translator.translate(single_cord, _screen_origin, _graph_origin));
    }

    return screen_cords;
}