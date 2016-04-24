#include "RGBImageStudent.h"
#include <iostream>
#include "ImageIO.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	for (int i = 0; i < other.getWidth(); ++i){
		for (int j = 0; j < other.getHeight(); ++j){
			RGB p = other.getPixel(i, j);
			setPixel(i, j, p);
		}
	}
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	rgbStorage = new RGB*[width];
	for (int i = 0; i < width; ++i)
		rgbStorage[i] = new RGB[height];
}

RGBImageStudent::~RGBImageStudent() {
	for (int i = 0; i < getWidth(); ++i)
		delete[] rgbStorage[i];
	delete[] rgbStorage;
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);

	if (rgbStorage != nullptr){
		for (int i = 0; i < getWidth(); ++i)
			delete[] rgbStorage[i];
		delete[] rgbStorage;
	}


	rgbStorage = new RGB*[getWidth()];
	for (int i = 0; i < getWidth(); ++i)
		rgbStorage[i] = new RGB[getHeight()];
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	for (int i = 0; i < getWidth(); ++i)
		delete[] rgbStorage[i];
	delete[] rgbStorage;

	RGBImage::set(other.getWidth(), other.getHeight());

	rgbStorage = new RGB*[getWidth()];
	for (int i = 0; i < getWidth(); ++i)
		rgbStorage[i] = new RGB[getHeight()];

	for (int i = 0; i < getWidth(); ++i)
		for (int j = 0; j < getHeight(); ++j)
			rgbStorage[i][j] = other.getPixel(getWidth(), getHeight());

}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	if ((x >= 0 && x <= getWidth()) && (y >= 0 && y <= getHeight()))
		rgbStorage[x][y] = pixel;
	else
		std::cout << "out of range\n";
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	RGB *p = &rgbStorage[0][0];
	*(p + i) = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	if ((x >= 0 && x <= getWidth()) && (y >= 0 && y <= getHeight()))
		return rgbStorage[x][y];
	
	return 0;
}

RGB RGBImageStudent::getPixel(int i) const { // needs checking
	if (i >= 0 && i <= (getWidth() * getHeight())){
		RGB *p = &rgbStorage[0][0];
		return *(p + i);
	}

	return 0;
}