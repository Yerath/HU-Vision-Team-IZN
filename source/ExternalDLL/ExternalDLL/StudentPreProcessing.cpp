#include "StudentPreProcessing.h"
#include "ImageFactory.h"
#include "ImageIO.h"
#include <iostream>

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {

	const int WIDTH = 200;
	const int HEIGHT = 200;
	//ImageIO::showImage(image);
	IntensityImage * result = ImageFactory::newIntensityImage(WIDTH, HEIGHT);




	//Nearest-neighbor interpolation
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			result->setPixel(j, i, image.getPixel(0, 0));
		}
	}

	double scale_height = image.getHeight() / (double)HEIGHT;
	double scale_width = image.getWidth() / (double)WIDTH;
	int nearHeight = 0;
	int nearWidth = 0;
	

	int max_dim = (image.getWidth() >= image.getHeight()) ? image.getWidth() : image.getHeight();
	float scale = ((float)WIDTH) / max_dim;
	std::cout << scale << " \n ";

	//to-do add height code
	/*if (image.getWidth() >= image.getHeight()) {

	}
	else {

	}*/

	for (int i = 0; i < HEIGHT; ++i) {
		nearHeight = (int)(scale_height * i);
		for (int j = 0; j < WIDTH; ++j) {
			nearWidth = (int)(scale_width * j);
		//	std::cout << nearWidth << "  " <<nearHeight << "\n";
			result->setPixel(j * scale + ((WIDTH - scale * WIDTH)/2),i,image.getPixel(nearWidth, nearHeight));
		}
	}
	ImageIO::showImage(image, "testwindow");
	ImageIO::showImage(*result);
	return result;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}