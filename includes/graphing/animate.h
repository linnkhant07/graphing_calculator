#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "system.h"
#include "textbox.h"
#include "sidebar.h"
#include "graph_info.h"
#include "button.h"
#include "help.h"

class animate
{
public:
    animate();
    void run();
    void processEvents();
    void update();
    void render();
    void Step();
    void Draw();

private:
    // the usual
    sf::RenderWindow window;
    System system;    // container for all the animated objects
    int command;      // command to send to system
    sf::Font font;    // font to draw on main screen
    Sidebar sidebar;  // rectangular message sidebar
    Button graph_btn; // graph btn
    Button clear_btn; // clear btn
    Help help;        // help box

    // for graphing
    graph_info *info;
};

#endif
