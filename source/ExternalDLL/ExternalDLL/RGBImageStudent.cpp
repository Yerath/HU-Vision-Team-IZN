#include "RGBImageStudent.h"
#include <iostream>

RGBImageStudent::RGBImageStudent() : RGBImage() {
	//int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	//int throwError = 0, e = 1 / throwError;
	//TODO: Create a copy from the other object
	//*this = other;
	//width = other.getWidth();
	//height = other.getHeight();
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height), swidth(width), sheight(height) {
	rgbStorage = new RGB*[swidth];
	for (int i = 0; i < swidth; ++i)
		rgbStorage[i] = new RGB[height];
}

RGBImageStudent::~RGBImageStudent() {
	for (int i = 0; i < swidth; ++i)
		delete[] rgbStorage[i];
	delete[] rgbStorage;
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);

	//int throwError = 0, e = 1 / throwError;
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
	//RGB** temp = rgbStorage;
	if (rgbStorage != nullptr){
		for (int i = 0; i < swidth; ++i)
			delete[] rgbStorage[i];
		delete[] rgbStorage;
	}

	swidth = width;
	sheight = height;

	rgbStorage = new RGB*[swidth];
	for (int i = 0; i < swidth; ++i)
		rgbStorage[i] = new RGB[sheight];

	/*for (int i = 0; i < N; ++i)
	for (int j = 0; j < M; ++j)
	ary[i][j] = i;*/


}

void RGBImageStudent::set(const RGBImageStudent &other) {
	//RGBImage::set(other.getWidth(), other.getHeight());
	//int throwError = 0, e = 1 / throwError;
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
	for (int i = 0; i < swidth; ++i)
		delete[] rgbStorage[i];
	delete[] rgbStorage;

	swidth = other.getWidth();
	sheight = other.getHeight();

	rgbStorage = new RGB*[swidth];
	for (int i = 0; i < swidth; ++i)
		rgbStorage[i] = new RGB[sheight];

	for (int i = 0; i < swidth; ++i)
		for (int j = 0; j < sheight; ++j)
			rgbStorage[i][j] = other.getPixel(swidth, sheight);

}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	//int throwError = 0, e = 1 / throwError;
	//TODO: no comment needed :)
	//if ((x > 0 && x >= swidth) && (y > 0 && y >= sheight)) {
	rgbStorage[x][y] = pixel;
	//}
	//else {
	//	std::cout << "out of range\n";
	//}
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	//int throwError = 0, e = 1 / throwError;
	/*
	* TODO: set pixel i in "Row-Major Order"
	*
	*
	* Original 2d image (values):
	* 9 1 2
	* 4 3 5
	* 8 7 8
	*
	* 1d representation (i, value):
	* i		value
	* 0		9
	* 1		1
	* 2		2
	* 3		4
	* 4		3
	* 5		5
	* 6		8
	* 7		7
	* 8		8
	*/
	//int x = i % swidth
	RGB *arr2 = (RGB*)rgbStorage;
	arr2[i] = pixel;
	//rgbStorage[swidth]
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	//int throwError = 0, e = 1 / throwError;
	//TODO: no comment needed :)
	//	if ((x > 0 && x <= swidth) && (y > 0 && y <= sheight)) {
	return rgbStorage[x][y];
	//}
	//else {
	//	std::cout << "out of range\n";
	//}
	return 0;
}

RGB RGBImageStudent::getPixel(int i) const {
	int throwError = 0, e = 1 / throwError;
	//TODO: see setPixel(int i, RGB pixel)
	return 0;
}