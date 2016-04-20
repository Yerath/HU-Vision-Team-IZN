#include "RGBImageStudent.h"
#include <iostream>
#include "ImageIO.h"

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
}

void RGBImageStudent::set(const RGBImageStudent &other) {
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
	if ((x >= 0 && x <= swidth) && (y >= 0 && y <= sheight))
		rgbStorage[x][y] = pixel;
	else
		std::cout << "out of range\n";
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	RGB *p = &rgbStorage[0][0];
	*(p + i) = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	if ((x >= 0 && x <= swidth) && (y >= 0 && y <= sheight))
		return rgbStorage[x][y];
	
	return 0;
}

RGB RGBImageStudent::getPixel(int i) const {
	if (i >= 0 && i <= (swidth * sheight)){
		RGB *p = &rgbStorage[0][0];
		return *(p + i);
	}

	return 0;
}

IntensityImageStudent & RGBImageStudent::RGBGRAY() {
	IntensityImageStudent *ss = new IntensityImageStudent;
	ss->set(swidth, sheight);

	for (int i = 0; i < swidth; ++i){
		for (int j = 0; j < sheight; ++j){
			RGB p = rgbStorage[i][j];

			Intensity x = 0.2989 * (p.r) + 0.5870 * (p.g) + 0.1140 * (p.b);
			//std::cout << "x:" << i << " y:" << j << " " << x << "\n";
			ss->setPixel(i, j, x);
		}
	}
	std::cout << (int)ss->getPixel(0, 0) << "dd\n";
	ImageIO::showImage(*ss);
	return *ss;
	

}