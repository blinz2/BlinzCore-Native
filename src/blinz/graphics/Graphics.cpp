#include "../__Shared.hpp"
#include "../util/ResourceManager.hpp"
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Graphics.hpp"

using sf::Image;
using sf::Sprite;
using sf::Window;

ResourceManager<Sprite*> images;
char red = 0, green = 0, blue = 0, alpha = 255;

void initializeScreen(const char* title, int width = 1024, int height = 768) {
	window.Create(sf::VideoMode(width, height, 32), title);
}

int loadImage(const char* path) {
	Image image;
	image.LoadFromFile(path);
	Sprite *sprite = new Sprite();
	sprite->SetImage(image);
	images.add(sprite);
}

void unloadImage(int index) {
	delete images.remove(index);
}

void updateGraphics() {
}

void setColor(int r, int g, int b) {
	red = r;
	green = g;
	blue = b;
}

void drawLine(int x1, int y1, int x2, int y2) {
}

void drawRect(int x1, int y1, int x2, int y2) {
}
