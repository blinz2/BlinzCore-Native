#include "SDL/SDL.h"
#include "Key.hpp"

/*
 * Event:
 * 	bits
 * 	00     0 = key/button status alteration, 1 = mouse wheel scroll
 * 	32-48  x coordinate of the cursor on screen
 * 	48-64  y coordinate of the cursor on screen
 * Button/Key status alteration events:
 * 	01     0 = keyboard, 1 = mouse
 * 	02     0 = release, 1 = press
 * 	03-31  button/key identification
 * Mouse wheel scroll:
 * 	01-31  scroll distance
 */

long mouseButtonPress(short button, long x, long y);
long mouseButtonRelease(short button, long x, long y);
long mouseWheelScroll(short scrollDistance, long x, long y);
long keyPress(short button);
long keyRelease(short key);
long updateInput();

