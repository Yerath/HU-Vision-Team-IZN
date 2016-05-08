#include "StudentLocalization.h"
#include "IntensityImageStudent.h"
#include "ImageIO.h" //Image load and save functionality

bool StudentLocalization::stepFindHead(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindNoseMouthAndChin(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindChinContours(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindNoseEndsAndEyes(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindExactEyes(const IntensityImage &image, FeatureMap &features) const {
	int k1 = 0, k2 = 1, k3 = 0,
		k4 = 1, k5 = 1, k6 = 1,
		k7 = 0, k8 = 1, k9 = 0;
	int ksum = (k1 + k2 + k3 + k4 + k5 + k6 + k7 + k8 + k9);
	IntensityImageStudent tempiamge(image);

		for (int i = 0; i < image.getWidth(); ++i){
			for (int j = 0; j < image.getHeight(); ++j){
				//int tmp = image.getPixel(i, j);
				int s = k1 * image.getPixel(i - 1, j - 1)
					+ k2 * image.getPixel(i, j - 1)
					+ k3 * image.getPixel(i + 1, j - 1)
					+ k4 * image.getPixel(i - 1, j)
					+ k5 * image.getPixel(i, j)
					+ k6 * image.getPixel(i + 1, j)
					+ k7 * image.getPixel(i - 1, j + 1)
					+ k8 * image.getPixel(i, j + 1)
					+ k9 * image.getPixel(i + 1, j + 1);
				float tmp = s / ksum;
				tempiamge.setPixel(i, j, s);
			}
		}

		//ImageIO::showImage(image);
		ImageIO::showImage(tempiamge);
	
	return false;
}