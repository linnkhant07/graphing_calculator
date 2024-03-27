#include "help.h"
#include "iostream"
#include "constants.h"
#include <SFML/Graphics.hpp>

using namespace std;

Help::Help()
{
    // Initialize the background box
    sf::Vector2f boxSize(800, 400);
    background.setSize(boxSize);
    background.setFillColor(sf::Color(200, 200, 200));

    // // set the origin as the center point
    background.setOrigin(boxSize / 2.f);

    // Initialize the text
    cout << "Sidebar CTOR: about to load font." << endl;

    if (!font.loadFromFile("Roboto-Thin.ttf"))
    {
        cout << "Sidebar() CTOR: Font failed to load" << endl;
        cin.get();
        exit(-1);
    }
    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    cout << "Sidebar CTOR: loaded font." << endl;
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(20);
    text.setStyle(sf::Text::Bold);
    text.setString("Keys\t\t\t\t\t Actions\n\n"
                   "Up, Down \t\t\t Zoom In, Zoom Out\n\n"
                   "LEFT,RIGHT \t\tPan Left, Pan Right \n\n\n"
                   "Tips:\n"
                   "Click on the functions in the history bar to quickly graph them.\n"
                   "Clear History will clear all your function history.\n"
                   "The program will remember your function history even if you close it.\n");

    // Initialize the close button for the help box
    sf::Vector2f buttonSize(20, 20);
    btn_close = Button("X", buttonSize, 20, sf::Color::Red, sf::Color::White);
    btn_close.setFont(font);
    btn_close.setBold();
}

void Help::show(sf::RenderWindow &window)
{
    // show only if visibility is on
    if (!isBoxVisible)
    {
        return;
    }

    // Position the help box in the center of the screen
    background.setPosition({WORK_PANEL / 2, SCREEN_HEIGHT / 2});

    // Position the close button in the top-right corner of the help box
    sf::Vector2f boxPos(background.getPosition());
    sf::Vector2f boxSize(background.getSize());
    btn_close.setPosition({boxPos.x + boxSize.x / 2.f - btn_close.getGlobalBounds().width,
                           boxPos.y - boxSize.y / 2.f});

    sf::FloatRect pos = background.getLocalBounds();

    // position the text in the center
    sf::FloatRect textBounds(text.getLocalBounds());
    text.setOrigin((textBounds.left + textBounds.width) / 2, (textBounds.top + textBounds.height) / 2);
    text.setPosition({WORK_PANEL / 2, SCREEN_HEIGHT / 2});

    // Draw the help box and its contents
    window.draw(background);
    btn_close.drawTo(window);
    window.draw(text);
}

void Help::drawSmallIcon(sf::RenderWindow &window)
{

    float iconPadding = 10.f;

    sf::Vector2f buttonSize(20, 20);
    btn_icon = Button("?", buttonSize, 20, sf::Color::White, sf::Color::Black);
    btn_icon.setBold();
    btn_icon.setFont(font);
    btn_icon.setPosition({iconPadding, iconPadding});
    btn_icon.drawTo(window);
}

bool Help::isButtonsHover(sf::RenderWindow &window)
{
    // when the big box is showing
    if (isBoxVisible)
        // either button is hovered
        return btn_close.isMouseOver(window) || btn_icon.isMouseOver(window);

    return btn_icon.isMouseOver(window);
}
