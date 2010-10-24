#include "SDL/SDL.h"
#include "SDL/SDL_gfxPrimitives.h"
#include "SDL/SDL_image.h"
#include "../__Shared.hpp"
#include "../util/ResourceManager.hpp"
#include "Graphics.hpp"

ResourceManager<SDL_Surface*> images;
Uint8 red = 0, green = 0, blue = 0, alpha = 255;

bool initializeScreen(const char* title, int width, int height) {
	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode(width, height, 24, SDL_DOUBLEBUF);
	SDL_WM_SetCaption(title, title);
	atexit(SDL_Quit);
	return screen != 0;
}

int loadImage(const char* path) {
	SDL_Surface* img1 = IMG_Load(path);
	SDL_Surface* img2 = SDL_DisplayFormat(img1);
	SDL_FreeSurface(img1);
	return images.add(img1);
}

void unloadImage(int index) {
	SDL_FreeSurface(images.remove(index));
}

void updateGraphics() {
	SDL_Flip(screen);
}

void setColor(int r, int g, int b) {
	red = r;
	green = g;
	blue = b;
}

void drawLine(int x1, int y1, int x2, int y2) {
	lineRGBA(screen, x1, y1, x2, y2, red, green, blue, alpha);
}

void drawRect(int x1, int y1, int x2, int y2) {
	SDL_Rect r;
	r.x = x1;
	r.y = y1;

}
