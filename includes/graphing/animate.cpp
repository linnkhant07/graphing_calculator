#include "animate.h"
#include "constants.h"
#include <iostream>
#include "system.h"
#include <string.h>
#include "button.h"
#include "help.h"
#include "fstream"

using namespace std;

animate::animate() : sidebar(WORK_PANEL, SIDE_BAR, info), system(info), help()

{
    cout << "animate CTOR: TOP" << endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Viva El Grafico");

    // read equations from the input file
    Queue<string> equations;
    ifstream cin("history.txt");
    string line;
    while (getline(cin, line))
    {
        equations.push(line);
    }
    cin.close();

    // GRAPH INFO
    info = new graph_info(equations, sf::Vector2f(SCREEN_HEIGHT, SCREEN_WIDTH), sf::Vector2f(SCREEN_HEIGHT / 2, SCREEN_HEIGHT / 2), sf::Vector2f(10, 10), sf::Vector2f(-6, 6));

    sidebar.setFunctions(equations); // set functions to display on sidebar
    system = System(info);           // instantiates system with g_info
    window.setFramerateLimit(15);

    // fontStuff
    cout << "Geme CTOR. preparing to load the font." << endl;
    if (!font.loadFromFile("arial.ttf"))
    {
        cout << "animate() CTOR: Font failed to load" << endl;
        cin.get();
        exit(-1);
    }
    cout << "animate instantiated successfully." << endl;

    // instantiate buttons
    //  g raph button
    graph_btn = Button("Graph", {150, 50}, 20, sf::Color::Black, sf::Color::White);
    graph_btn.setFont(font);
    graph_btn.setPosition({WORK_PANEL + 42, SCREEN_HEIGHT - 150});

    // Clear History Button
    clear_btn = Button("Clear History", {150, 50}, 20, sf::Color(0x355CDD), sf::Color::White);
    clear_btn.setFont(font);
    clear_btn.setPosition({WORK_PANEL + 42, SCREEN_HEIGHT - 80});
}

void animate::Step()
{
    // cause changes to the data for the next frame
    system.Step(command, info);
    command = 0;
}

void animate::Draw()
{
    system.Draw(window, info); // pass on the draw to system
    sidebar.draw(window);      // draw sidebar and input box
    graph_btn.drawTo(window);  // draw buttons
    clear_btn.drawTo(window);
    help.drawSmallIcon(window); // draw help boxes
    help.show(window);
}

void animate::update()
{
    Step();
}
void animate::render()
{
    window.clear();
    Draw();
    window.display();
}

void animate::processEvents()
{
    sf::Event event;
    float mouseX, mouseY;
    while (window.pollEvent(event))
    {
        // check the type of the event...
        switch (event.type)
        {
        // window closed
        case sf::Event::Closed:
        {
            // open the file and save
            ofstream fout("history.txt");
            while (!info->_equations.empty())
            {
                fout << info->_equations.pop() << endl;
            }
            fout.close();
            window.close();
            break;
        }
        // add the text entered to input box
        case sf::Event::TextEntered:
            sidebar.textbox.typedOn(event);
            break;

        // key pressed
        case sf::Event::KeyPressed:
            switch (event.key.code)
            {
                // check for pan zoom escape
            case sf::Keyboard::Left:
                command = LEFT_KEY;
                break;
            case sf::Keyboard::Right:
                command = RIGHT_KEY;
                break;
            case sf::Keyboard::Up:
                command = UP_KEY;
                break;
            case sf::Keyboard::Down:
                command = DOWN_KEY;
                break;
            case sf::Keyboard::Escape:
                window.close();
                break;
            }

            break;

        // mouse toggles
        case sf::Event::MouseButtonPressed:

            // if clicked on text box -> selected
            if (sidebar.textbox.isBoxHover(window))
            {
                sidebar.textbox.setSelected(true);
            }

            // if graph button is clicked
            else if (graph_btn.isMouseOver(window))
            {
                string eq = sidebar.textbox.getText(); // get eq from input box

                // check if the queue is maxed
                if (info->_equations.size() >= MAX_EQUATIONS_SIZE)
                    info->_equations.pop();

                info->_equations.push(eq); // push the new equation

                // draw the latest equation
                info->drawIndex = info->_equations.size() - 1;

                sidebar.setFunctions(info->_equations); /////
            }

            else if (clear_btn.isMouseOver(window))
            {
                // clear the input box
                sidebar.textbox.setText("");

                // empty the queue
                while (!info->_equations.empty())
                {
                    string popped = info->_equations.pop();
                }

                // draw nothing
                info->drawIndex = -1;

                // update the sidebar
                sidebar.setFunctions(info->_equations);
            }

            else if (help.isButtonsHover(window))
            {
                // hide show the help page
                help.toggleHelp();
            }
            // if clicked anywhere - textbox unselected
            else
            {
                sidebar.textbox.setSelected(false);

                // if the function in history panel is clicked
                int index = sidebar.isFunctionHover(window);
                if (index >= 0)
                {
                    info->drawIndex = index;
                }
            }

            break;

        case sf::Event::MouseMoved:
        {
            int index = sidebar.isFunctionHover(window);
            // TO WORK ON LATER
            // CHANGE THE BACKGROUND COLOR WHEN THE FUNCTIONS GOT HOVERED
        }
        default:
            break;
        }
    }
}
void animate::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render(); // clear/draw/display
    }
    cout << endl
         << "-------ANIMATE MAIN LOOP EXITING ------------" << endl;
}
