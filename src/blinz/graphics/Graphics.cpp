#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "../util/ResourceManager.hpp"
#include "Graphics.hpp"

ResourceManager<SDL_Surface*> images;

int loadImage(const string* path) {
	SDL_Surface* img1 = IMG_Load(path->c_str());
	SDL_Surface* img2 = SDL_DisplayFormat(img1);
	SDL_FreeSurface(img1);
	return images.add(img1);
}

void unloadImage(int index) {
	SDL_FreeSurface(images.remove(index));
}

