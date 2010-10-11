#include <string>

using std::string;

/**
 * Initializes the screen.
 * @param the title for the screen
 * @param width the new width of the screen
 * @param height the new height of the screen
 */
bool initializeScreen(const string* title, int width, int height);

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
