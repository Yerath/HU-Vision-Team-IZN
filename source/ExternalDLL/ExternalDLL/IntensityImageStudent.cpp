#include "IntensityImageStudent.h"
#include <iostream>

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	//int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()){
	//int throwError = 0, e = 1 / throwError;
	createStorage();
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
//	int throwError = 0, e = 1 / throwError;
	createStorage();
}

IntensityImageStudent::IntensityImageStudent(const RGBImage &rgbimage){
	IntensityImage::set(rgbimage.getWidth(), rgbimage.getHeight());
	createStorage();

	for (int i = 0; i < rgbimage.getWidth(); ++i){
		for (int j = 0; j < rgbimage.getHeight(); ++j){
			RGB p = rgbimage.getPixel(i, j);

			Intensity x = 0.2989 * (p.r) + 0.5870 * (p.g) + 0.1140 * (p.b);
			//std::cout << "x:" << i << " y:" << j << " " << x << "\n";
			setPixel(i, j, x);
		}
	}
}

IntensityImageStudent::~IntensityImageStudent() {
//	int throwError = 0, e = 1 / throwError;
	//TODO: delete allocated objects
	deleteStorage();
}

void IntensityImageStudent::set(const int width, const int height) {

	deleteStorage();
	IntensityImage::set(width, height);
	createStorage();
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {

	//int throwError = 0, e = 1 / throwError;

	deleteStorage(); 
	IntensityImage::set(other.getWidth(), other.getHeight());
	createStorage();

	/*for (int y = 0; y < sHeight; ++y){
		for (int x = 0; x < sWidth; ++x)
			intensityStorage[y][x] = other.getPixel(x, y);
	}*/

	for (int y = 0; y < getWidth(); ++y){
		for (int x = 0; x < getHeight(); ++x)
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

	intensityStorage = new Intensity*[getWidth()];
	for (int i = 0; i < getWidth(); ++i)
		intensityStorage[i] = new Intensity[getHeight()];

}

void IntensityImageStudent::deleteStorage(){
	for (int i = 0; i < getWidth(); ++i)
		delete[] intensityStorage[i];
	delete[] intensityStorage;
}