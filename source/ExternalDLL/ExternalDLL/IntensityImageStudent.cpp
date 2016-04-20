#include "IntensityImageStudent.h"
#include <iostream>

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) , sWidth(other.getWidth()), sHeight(other.getHeight()){
	int throwError = 0, e = 1 / throwError;

}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height), sWidth(width), sHeight(height) {
	int throwError = 0, e = 1 / throwError;
	createStorage();
}

IntensityImageStudent::~IntensityImageStudent() {
	int throwError = 0, e = 1 / throwError;
	//TODO: delete allocated objects
	deleteStorage();
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	int throwError = 0, e = 1 / throwError;

	deleteStorage(); sWidth = width; sHeight = height;
	createStorage();
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	int throwError = 0, e = 1 / throwError;

	deleteStorage(); sWidth = other.getWidth(); sHeight = other.getHeight();
	createStorage();

	for (int y = 0; y < sHeight; ++y){
		for (int x = 0; x < sWidth; ++x)
			intensityStorage[y][x] = other.getPixel(x, y);
	}
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	int throwError = 0, e = 1 / throwError;

	if (x > sWidth || y > sHeight)
		std::cout << "Pixel out of range"; return;

	intensityStorage[y][x] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	int throwError = 0, e = 1 / throwError;
	Intensity *p = &intensityStorage[0][0];
	*(p + i) = pixel;

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
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	int throwError = 0, e = 1 / throwError;
	//TODO: no comment needed :)

	if (x > sWidth || y > sHeight)
		std::cout << "Pixel out of range"; return 0;

	return intensityStorage[y][x];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	int throwError = 0, e = 1 / throwError;
	//TODO: see setPixel(int i, RGB pixel)

	if (i > (sWidth * sHeight))
		std::cout << "Pixel out of range"; return 0;

	Intensity *p = &intensityStorage[0][0];
	return *(p + i);
}

void IntensityImageStudent::createStorage(){
	if (intensityStorage != nullptr)
		deleteStorage();

	intensityStorage = new Intensity*[sHeight];
	for (int i = 0; i < sHeight; ++i)
		intensityStorage[i] = new Intensity[sWidth];

}

void IntensityImageStudent::deleteStorage(){
	for (int i = 0; i < sHeight; ++i)
		delete[] intensityStorage[i];
	delete[] intensityStorage;
}