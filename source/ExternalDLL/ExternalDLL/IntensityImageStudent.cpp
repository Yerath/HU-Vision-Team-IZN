#include "IntensityImageStudent.h"
#include <iostream>
#include <algorithm>    // std::max

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()){
	createStorage();
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	createStorage();
}

IntensityImageStudent::IntensityImageStudent(const RGBImage &rgbimage, int type){
	IntensityImage::set(rgbimage.getWidth(), rgbimage.getHeight());
	createStorage();

	switch (type){
		case 1:
			//Using averaging
			for (int i = 0; i < rgbimage.getWidth(); ++i){
				for (int j = 0; j < rgbimage.getHeight(); ++j){
					RGB p = rgbimage.getPixel(i, j);
					Intensity x = (p.r + p.g + p.b) / 3;
					setPixel(i, j, x);
				}
			}
		break;
	
		case 2:
			//Grayscaling with correcting for the human eye (Luminance)
			for (int i = 0; i < rgbimage.getWidth(); ++i){
				for (int j = 0; j < rgbimage.getHeight(); ++j){
					RGB p = rgbimage.getPixel(i, j);
					Intensity x = 0.2989 * (p.r) + 0.5870 * (p.g) + 0.1140 * (p.b);
					setPixel(i, j, x);
				}
			}
			break;

		case 3:
			//Using decomposition
			for (int i = 0; i < rgbimage.getWidth(); ++i){
				for (int j = 0; j < rgbimage.getHeight(); ++j){
					RGB p = rgbimage.getPixel(i, j);
					Intensity x = (std::max({ p.r, p.g, p.b }) + std::min({ p.r, p.g, p.b })) / 2;
					setPixel(i, j, x);
				}
			}
			break;

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