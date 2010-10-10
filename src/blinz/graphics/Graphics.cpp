#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "../util/ResourceManager.hpp"
#include "Graphics.hpp"

SDL_Surface* screen = 0;
ResourceManager<SDL_Surface*> images;

void initializeScreen(int width, int height) {
	screen = SDL_SetVideoMode(width, height, 24, SDL_DOUBLEBUF);
}

int loadImage(const string* path) {
	SDL_Surface* img1 = IMG_Load(path->c_str());
	SDL_Surface* img2 = SDL_DisplayFormat(img1);
	SDL_FreeSurface(img1);
	return images.add(img1);
}

void unloadImage(int index) {
	SDL_FreeSurface(images.remove(index));
}

