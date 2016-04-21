#include "IntensityImageStudent.h"
#include <iostream>

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	//int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) , sWidth(other.getWidth()), sHeight(other.getHeight()){
	//int throwError = 0, e = 1 / throwError;
	createStorage();
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height), sWidth(width), sHeight(height) {
//	int throwError = 0, e = 1 / throwError;
	createStorage();
}

IntensityImageStudent::~IntensityImageStudent() {
//	int throwError = 0, e = 1 / throwError;
	//TODO: delete allocated objects
	deleteStorage();
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
//	int throwError = 0, e = 1 / throwError;

	deleteStorage();
	sWidth = width; 
	sHeight = height;
	createStorage();
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	//int throwError = 0, e = 1 / throwError;

	deleteStorage(); 
	sWidth = other.getWidth(); 
	sHeight = other.getHeight();
	createStorage();

	/*for (int y = 0; y < sHeight; ++y){
		for (int x = 0; x < sWidth; ++x)
			intensityStorage[y][x] = other.getPixel(x, y);
	}*/

	for (int y = 0; y < sWidth; ++y){
		for (int x = 0; x < sHeight; ++x)
			intensityStorage[x][y] = other.getPixel(x, y);
	}

	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	//int throwError = 0, e = 1 / throwError;
	//
	//if (x > sWidth || y > sHeight)
	//	std::cout << "Pixel out of range"; return;

	//std::cout << "x:"<<x << " y:"<<y <<" " <<pixel << "\n";
	intensityStorage[x][y] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	//int throwError = 0, e = 1 / throwError;
	//Intensity *p = &intensityStorage[0][0];
	//*(p + i) = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	//int throwError = 0, e = 1 / throwError;
	//TODO: no comment needed :)

	//if (x > sWidth || y > sHeight)
	//	std::cout << "Pixel out of range"; return 0;

	return intensityStorage[x][y];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	//int throwError = 0, e = 1 / throwError;
	//TODO: see setPixel(int i, RGB pixel)

	/*if (i > (sWidth * sHeight))
		std::cout << "Pixel out of range"; return 0;

	Intensity *p = &intensityStorage[0][0];
	return *(p + i);*/
	return 0;
}

void IntensityImageStudent::createStorage(){
	if (intensityStorage != nullptr)
		deleteStorage();

	intensityStorage = new Intensity*[sWidth];
	for (int i = 0; i < sWidth; ++i)
		intensityStorage[i] = new Intensity[sHeight];

}

void IntensityImageStudent::deleteStorage(){
	for (int i = 0; i < sWidth; ++i)
		delete[] intensityStorage[i];
	delete[] intensityStorage;
}