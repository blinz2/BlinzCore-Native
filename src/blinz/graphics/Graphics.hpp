#include <string>

using std::string;

bool initializeScreen(const string* title, int width, int height);

void setScreenSize(int width, int height);

int loadImage(const string* path);

void unloadImage(int index);
