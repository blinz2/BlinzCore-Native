#include <string>

using std::string;

/**
 * Initializes the screen.
 * @param the title for the screen
 * @param width the new width of the screen
 * @param height the new height of the screen
 */
bool initializeScreen(const char* title, int width, int height);

/**
 * Sets the screen size.
 * @param width the new width of the screen
 * @param height the new height of the screen
 */
void setScreenSize(int width, int height);

/**
 * Loads the image.
 * @param path path to the image on the disk
 * @return the identification number for handling the image
 */
int loadImage(const string* path);

/**
 * Unloads the image from memory.
 * @param index the identification number of the image to unload
 */
void unloadImage(int index);

/**
 * Updates the graphics system, should be updated once per draw cycle.
 */
void updateGraphics();

/**
 * Sets the color with which graphics primitives will be drawn.
 * @param red the red value of the RGB color
 * @param green the green value of the RGB color
 * @param blue the blue value of the RGB color
 */
void setColor(int red, int green, int blue);

/**
 * Draws a line from the first point to the second point.
 * @param x1 the x coordinate of point 1
 * @param y1 the y coordinate of point 1
 * @param x2 the x coordinate of point 2
 * @param y2 the y coordinate of point 2
 */
void drawLine(int x1, int y1, int x2, int y2);

/**
 * Draws a rectangle.
 * @param x1 the x coordinate of rectangle
 * @param y1 the y coordinate of rectangle
 * @param x2 the x coordinate of rectangle
 * @param y2 the y coordinate of rectangle
 */
void drawRect(int x1, int y1, int x2, int y2);
