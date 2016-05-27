#include "StudentKernal.h"
#include <iostream>
#include "ImageIO.h"


IntensityImageStudent * StudentKernal::applyKernal(const IntensityImage &image, int mask[3][3],bool div, bool sub) {
	IntensityImageStudent * temp = new IntensityImageStudent(image);
	int sum = 0;
	for (int xm = 0; xm < 3; xm++){
		for (int xy = 0; xy < 3; xy++){
			//	std::cout << xm-1 <<  "  "  << xy -1<<  " " << mask[xm][xy]<<"\n";
			//intent += (mask[xm][xy] * image.getPixel(x + (xm - 1), y + (xy - 1)));
			sum += mask[xm][xy];
		}
	}
	if (sum == 0) {
		sum = 1;
	}
	else {
		sum = sum / 1;
	}
	for (int x = 0; x < image.getWidth(); x++) {
		for (int y = 0; y < image.getHeight(); y++) {
			int intent = 0;
			for (int xm = 0; xm < 3; xm++){
				for (int xy = 0; xy < 3; xy++){
				//	std::cout << xm-1 <<  "  "  << xy -1<<  " " << mask[xm][xy]<<"\n";
					intent += (mask[xm][xy] * image.getPixel(x + (xm -1), y + (xy-1)));
				}
			}
			//system("pause");
			if (div) {
				if (sub) {
					temp->setPixel(x, y, image.getPixel(x,y)-(intent / sum));
				}
				else {
					temp->setPixel(x, y, intent / sum);
				}
			}
			else {
				if (sub) {
					temp->setPixel(x, y, image.getPixel(x, y) - intent );
				}
				else {
					temp->setPixel(x, y, intent);
				}
			}
		}
	}
//ImageIO::showImage(temp);
	return temp;
}