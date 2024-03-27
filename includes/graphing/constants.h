#ifndef CONSTANTS_H
#define CONSTANTS_H
const float SCREEN_WIDTH = 1200;
const float SCREEN_HEIGHT = 600;
const float RADIUS = 1.5;

const float WORK_PANEL = SCREEN_WIDTH * 4 / 5;
const float SIDE_BAR = SCREEN_WIDTH * 1 / 5;
const float NUM_OF_POINTS = SCREEN_WIDTH * 4;

// for keys
enum keys
{
    LEFT_KEY = 1,
    RIGHT_KEY,
    UP_KEY,
    DOWN_KEY,
    DELETE = 8,
    ESCAPE,
    ENTER
};

const int SB_EQUATION = 0;
const int SB_MOUSE_POSITION = SB_EQUATION + 1;
const int SB_MOUSE_CLICKED = SB_MOUSE_POSITION + 1;
const int SB_KEY_PRESSED = SB_MOUSE_CLICKED + 1;

const int MAX_EQUATIONS_SIZE = 5;

#endif // CONSTANTS_H
