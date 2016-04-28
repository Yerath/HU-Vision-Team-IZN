#include "RGBImageStudent.h"
#include <iostream>
#include "ImageIO.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	rgbStorage = new RGB[getWidth() * getHeight()];
	for (int i = 0; i < other.getWidth(); ++i){
		for (int j = 0; j < other.getHeight(); ++j){
			RGB p = other.getPixel(i, j);
			setPixel(i, j, p);
		}
	}
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	rgbStorage = new RGB[getWidth() * getHeight()];
}

RGBImageStudent::~RGBImageStudent() {
	delete[] rgbStorage;
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);

	if (rgbStorage != nullptr){
		delete[] rgbStorage;
	}

	rgbStorage = new RGB[getWidth() * getHeight()];
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	delete[] rgbStorage;

	RGBImage::set(other.getWidth(), other.getHeight());

	rgbStorage = new RGB[getWidth() * getHeight()];
	for (int i = 0; i < getWidth(); ++i)
		for (int j = 0; j < getHeight(); ++j)
			rgbStorage[j * getWidth() + i] = other.getPixel(getWidth(), getHeight());

}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	if ((x >= 0 && x <= getWidth()) && (y >= 0 && y <= getHeight()))
		rgbStorage[y * getWidth() + x] = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	if (i >= 0 && i <= (getWidth() * getHeight()))
		rgbStorage[i] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	if ((x >= 0 && x <= getWidth()) && (y >= 0 && y <= getHeight()))
		return rgbStorage[y * getWidth() + x];
	return RGB();
}

RGB RGBImageStudent::getPixel(int i) const { // needs checking
	if (i >= 0 && i <= (getWidth() * getHeight()))
		return rgbStorage[i];
	return RGB();
}