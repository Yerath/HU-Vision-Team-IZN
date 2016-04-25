#include "IntensityImageStudent.h"
#include <iostream>

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()){
	createStorage();
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	createStorage();
}

IntensityImageStudent::IntensityImageStudent(const RGBImage &rgbimage){
	IntensityImage::set(rgbimage.getWidth(), rgbimage.getHeight());
	createStorage();

	for (int i = 0; i < rgbimage.getWidth(); ++i){
		for (int j = 0; j < rgbimage.getHeight(); ++j){
			RGB p = rgbimage.getPixel(i, j);

			Intensity x = 0.2989 * (p.r) + 0.5870 * (p.g) + 0.1140 * (p.b);
			setPixel(i, j, x);
		}
	}
}

IntensityImageStudent::~IntensityImageStudent() {
	deleteStorage();
}

void IntensityImageStudent::set(const int width, const int height) {

	deleteStorage();
	IntensityImage::set(width, height);
	createStorage();
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	deleteStorage(); 
	IntensityImage::set(other.getWidth(), other.getHeight());
	createStorage();


	for (int x = 0; x < getWidth(); ++x){
		for (int y = 0; y < getHeight(); ++y)
			intensityStorage[y * getWidth() + x] = other.getPixel(x, y);
	}

}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	if ((x >= 0 && x <= getWidth()) && (y >= 0 && y <= getHeight()))
		intensityStorage[y * getWidth() + x] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	if (i >= 0 && i <= (getWidth() * getHeight()))
		intensityStorage[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	if ((x >= 0 && x <= getWidth()) && (y >= 0 && y <= getHeight()))
		return intensityStorage[y * getWidth() + x];
	return Intensity();
}

Intensity IntensityImageStudent::getPixel(int i) const {
	if (i >= 0 && i <= (getWidth() * getHeight()))
		return intensityStorage[i];
	return Intensity();
}

void IntensityImageStudent::createStorage(){
	if (intensityStorage != nullptr)
		deleteStorage();
	intensityStorage = new Intensity[getWidth() * getHeight()];
}

void IntensityImageStudent::deleteStorage(){
	delete[] intensityStorage;
}