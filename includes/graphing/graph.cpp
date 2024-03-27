#include <iostream>
#include "graph.h"
#include "constants.h"
#include <unistd.h>

using namespace std;

void Graph::DrawAxis(sf::RenderWindow &window)
{
    // hold axis coordinates
    vector<sf::Vector2f> axis = _plotter.plot_axis();

    // draw them
    for (int i = 0; i < axis.size(); i++)
    {
        sf::CircleShape point(1);
        double x = axis[i].x;
        double y = axis[i].y;

        sf::Color CoolBlue(0x355C7D);
        point.setFillColor(CoolBlue);
        point.setPosition(sf::Vector2f(x, y));

        window.draw(point);
    }
}

void Graph::DrawTicks(sf::RenderWindow &window)
{
    // hold axis coordinates
    vector<sf::Vector2f> ticks = _plotter.plot_ticks('x');

    // draw them
    for (int i = 0; i < ticks.size(); i++)
    {
        sf::Color CoolBlue(0x355C7D);

        sf::RectangleShape tick;

        tick.setSize({3, 20});
        tick.setFillColor(CoolBlue);
        tick.setOrigin(tick.getGlobalBounds().width / 2, tick.getGlobalBounds().height / 2);
        double x = ticks[i].x;
        double y = ticks[i].y;

        tick.setPosition(sf::Vector2f(x, y));

        window.draw(tick);
    }
}

void Graph::Draw(sf::RenderWindow &window)
{

    if (_info->drawIndex >= 0)
    {
        // hold screen cord points
        _screen_cords = _plotter();

        // draw them
        for (int i = 0; i < _screen_cords.size(); i++)
        {
            sf::CircleShape point(RADIUS);
            double x = _screen_cords[i].x;
            double y = _screen_cords[i].y;

            sf::Color CoolYellow(0xFFCE30);
            point.setFillColor(sf::Color::White);
            point.setPosition(sf::Vector2f(x, y));

            window.draw(point);
        }
    }

    // don't forget to call drawAxis
    DrawAxis(window);
    // DrawTicks(window);
}
