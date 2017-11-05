#include "StudentPreProcessing.h"
#include "ImageFactory.h"
#include "ImageIO.h"
#include <iostream>

#include <time.h> 

clock_t start, finish;


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	return nullptr;
}


// t is a value that goes from 0 to 1 to interpolate in a C1 continuous way across uniformly sampled data points.
// when t is 0, this will return B.  When t is 1, this will return C.  Inbetween values will return an interpolation
// between B and C.  A and B are used to calculate slopes at the edges.
float cubic_hermite(float A, float B, float C, float D, float t) {

	float a = -A / 2.0f + (3.0f*B) / 2.0f - (3.0f*C) / 2.0f + D / 2.0f;
	float b = A - (5.0f*B) / 2.0f + 2.0f*C - D / 2.0f;
	float c = -A / 2.0f + C / 2.0f;
	float d = B;

	return a*t*t*t + b*t*t + c*t + d;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {

	const int WIDTH = 150;
	const int HEIGHT = image.getHeight() * ((double)150 / (double)image.getWidth());
	IntensityImage * result = ImageFactory::newIntensityImage(WIDTH, HEIGHT);


	if (false) {
		//Nearest-neighbor interpolation

		start = clock();
		for (int i = 0; i < HEIGHT; ++i) {
			for (int j = 0; j < WIDTH; ++j) {
			//	std::cout << nearWidth << "  " <<nearHeight << "\n";
				double nearHeight = (double)(i * image.getHeight()) / HEIGHT;
				double nearWidth = (double)(j * image.getWidth()) / WIDTH;
				
				result->setPixel(j,i,image.getPixel(nearWidth, nearHeight));
			}
		}
		finish = clock();
		std::cout << "Time for Nearest-neighbor interpolation (seconds): "
			<< ((double)(finish - start)) / CLOCKS_PER_SEC;
		ImageIO::showImage(image, "testwindow");
		ImageIO::saveIntensityImage(*result,"Nearest-neighbor.png");
		ImageIO::showImage(*result);
	}

	if (false) {
		//Bilinear Interpolation
		start = clock();
		for (int i = 0; i < HEIGHT; ++i) {
			for (int j = 0; j < WIDTH; ++j) {
				double nearHeight = (double)(i * image.getHeight()) / HEIGHT;
				double nearWidth = (double)(j * image.getWidth()) / WIDTH;

				int xj = (int)nearWidth;
				int yj = (int)nearHeight;


				Intensity p1 = image.getPixel(xj, yj);
				Intensity p2 = image.getPixel(xj+1, yj);
				Intensity p3 = image.getPixel(xj, yj+1);
				Intensity p4 = image.getPixel(xj+1, yj+1);


				Intensity p1x = p1 + (p2 - p1)* (nearWidth- xj);	 //lerp
				Intensity p2x = p3 + (p4 - p3)* (nearWidth - xj);	 //lerp
				Intensity p3x = p1x + (p3 - p1x)* (nearHeight - yj); //lerp


				result->setPixel(j , i, p3x);
			}
		}

		finish = clock();
		std::cout << "Time for Bilinear Interpolation (seconds): "
			<< ((double)(finish - start)) / CLOCKS_PER_SEC;
		ImageIO::showImage(image, "testwindow");
		ImageIO::saveIntensityImage(*result,"Bilinear.png");
		ImageIO::showImage(*result);
	}


	if (true) {
		//Bicubic Interpolation
		start = clock();
		for (int i = 0; i < HEIGHT; ++i) {
			for (int j = 0; j < WIDTH; ++j) {
				double nearHeight = (double)(i * image.getHeight()) / HEIGHT;
				double nearWidth = (double)(j * image.getWidth()) / WIDTH;

				int xj = (int)nearWidth;
				int yj = (int)nearHeight;


				Intensity p10 = image.getPixel(xj - 1, yj - 1);
				Intensity p20 = image.getPixel(xj + 0, yj - 1);
				Intensity p30 = image.getPixel(xj + 1, yj - 1);
				Intensity p40 = image.getPixel(xj + 2, yj - 1);

				Intensity p11 = image.getPixel(xj - 1, yj + 0);
				Intensity p21 = image.getPixel(xj + 0, yj + 0);
				Intensity p31 = image.getPixel(xj + 1, yj + 0);
				Intensity p41 = image.getPixel(xj + 2, yj + 0);

				Intensity p12 = image.getPixel(xj - 1, yj + 1);
				Intensity p22 = image.getPixel(xj + 0, yj + 1);
				Intensity p32 = image.getPixel(xj + 1, yj + 1);
				Intensity p42 = image.getPixel(xj + 2, yj + 1);

				Intensity p13 = image.getPixel(xj - 1, yj + 2);
				Intensity p23 = image.getPixel(xj + 0, yj + 2);
				Intensity p33 = image.getPixel(xj + 1, yj + 2);
				Intensity p43 = image.getPixel(xj + 2, yj + 2);


				float col0 = cubic_hermite(p10, p20, p30, p40, (nearWidth - xj));
				float col1 = cubic_hermite(p11, p21, p31, p41, (nearWidth - xj));
				float col2 = cubic_hermite(p12, p22, p32, p42, (nearWidth - xj));
				float col3 = cubic_hermite(p13, p23, p33, p43, (nearWidth - xj));

				

				int value = (int)cubic_hermite(col0, col1, col2, col3, (nearHeight - yj));

				result->setPixel(j, i, value);
			}
		}

		finish = clock();
		std::cout << "Time for Bicubic Interpolation (seconds): "
			<< ((double)(finish - start)) / CLOCKS_PER_SEC;
		ImageIO::showImage(image, "testwindow");
		ImageIO::saveIntensityImage(*result,"Bicubic.png");
		ImageIO::showImage(*result);
	}

	return result;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}