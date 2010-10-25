#include <GL/gl.h>
#include <IL/il.h>
#include "Image.hpp"

Image::Image(const char *path) {
	ilGenImages(1, &ilImageID);
	ilBindImage(ilImageID);
	ilLoadImage(path);
	width = ilGetInteger(IL_IMAGE_WIDTH);
	height = ilGetInteger(IL_IMAGE_HEIGHT);
}

void Image::load() {
	ilBindImage(ilImageID);

	if (ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE)) {
		glGenTextures(1, &glImageID);
		glBindTexture(GL_TEXTURE_2D, glImageID);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_BPP),
				ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT), 0,
				ilGetInteger(IL_IMAGE_FORMAT), GL_UNSIGNED_BYTE, ilGetData());
	}

	ilDeleteImages(1, &ilImageID);
}
