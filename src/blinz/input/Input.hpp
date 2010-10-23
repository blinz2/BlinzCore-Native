#include "SDL/SDL.h"
#include "Key.hpp"

/*
 * Event:
 * 	bits
 * 	00-01  0 = key/button status alteration, 1 = mouse wheel scroll, 2 = exit application, 3 = nothing
 * Button/Key status alteration events:
 * 	02     0 = keyboard, 1 = mouse
 * 	03     0 = release, 1 = press
 * 	04-31  button/key identification
 * 	32-48  x coordinate of the cursor on screen
 * 	48-64  y coordinate of the cursor on screen
 * Mouse wheel scroll:
 * 	02-31  scroll distance
 * 	32-48  x coordinate of the cursor on screen
 * 	48-64  y coordinate of the cursor on screen
 */

long mouseButtonPress(short button, long x, long y);
long mouseButtonRelease(short button, long x, long y);
long mouseWheelScroll(short scrollDistance, long x, long y);
long keyPress(short button);
long keyRelease(short key);
long getInput();

