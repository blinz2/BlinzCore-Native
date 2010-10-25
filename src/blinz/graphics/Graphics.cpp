#include <vector>
#include "../__Shared.hpp"
#include "../util/ResourceManager.hpp"
#include "Image.hpp"
#include "Graphics.hpp"

using std::vector;
using sf::Window;

vector<int> imagesToLoad, imagesToDelete;
ResourceManager<Image*> images;
char red = 0, green = 0, blue = 0, alpha = 255;

void initializeScreen(const char* title, int width = 1024, int height = 768) {
	window.Create(sf::VideoMode(width, height, 32), title);
}

int loadImage(const char* path) {
	images.add(new Image(path));
}

void unloadImage(int index) {
	images.remove(index);
}

void updateGraphics() {
	while (imagesToLoad.size() > 0) {
		images.get(imagesToLoad[imagesToLoad.back()])->load();
		imagesToLoad.pop_back();
	}
}

void setColor(int r, int g, int b) {
	red = r;
	green = g;
	blue = b;
}

void drawImage(int imageID, int x1, int y1, int x2, int y2) {
}

void drawLine(int x1, int y1, int x2, int y2) {
}

void drawRect(int x1, int y1, int x2, int y2) {
}
