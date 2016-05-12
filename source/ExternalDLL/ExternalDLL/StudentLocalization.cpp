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
	/*int k1 = 0, k2 = 1, k3 = 0,
		k4 = 1, k5 = 1, k6 = 1,
		k7 = 0, k8 = 1, k9 = 0;
	int ksum = (k1 + k2 + k3 + k4 + k5 + k6 + k7 + k8 + k9);

	int k1s = 1, k2s = 2, k3s = 1,
		k4s = 2, k5s = 4, k6s = 2,
		k7s = 1, k8s = 2, k9s = 1;
	int ksums = (k1s + k2s + k3s + k4s + k5s + k6s + k7s + k8s + k9s);

	int k1sh = 0, k2sh = -1, k3sh = 0,
		k4sh = -1, k5sh = 4, k6sh = -1,
		k7sh = 0, k8sh = -1, k9sh = 0;
	int ksumsh = (k1sh + k2sh + k3sh + k4sh + k5sh + k6sh + k7sh + k8sh + k9sh);

	IntensityImageStudent tempiamge(image);

	for (int i = 0; i < image.getWidth(); ++i){
		for (int j = 0; j < image.getHeight(); ++j){
			//int tmp = image.getPixel(i, j);
			int sk = k1s * image.getPixel(i - 1, j - 1)
				+ k2s * image.getPixel(i, j - 1)
				+ k3s * image.getPixel(i + 1, j - 1)
				+ k4s * image.getPixel(i - 1, j)
				+ k5s * image.getPixel(i, j)
				+ k6s * image.getPixel(i + 1, j)
				+ k7s * image.getPixel(i - 1, j + 1)
				+ k8s * image.getPixel(i, j + 1)
				+ k9s * image.getPixel(i + 1, j + 1);
			float tmp = sk / (ksums);

			tempiamge.setPixel(i, j,  tmp);
		}
	}
	ImageIO::showImage(tempiamge);
	IntensityImageStudent tempiamges(tempiamge);

	for (int i = 0; i < tempiamge.getWidth(); ++i){
		for (int j = 0; j < tempiamge.getHeight(); ++j){
				//int tmp = image.getPixel(i, j);
			int s = k1 * tempiamge.getPixel(i - 1, j - 1)
				+ k2 * tempiamge.getPixel(i, j - 1)
				+ k3 * tempiamge.getPixel(i + 1, j - 1)
				+ k4 * tempiamge.getPixel(i - 1, j)
					+ k5 * tempiamge.getPixel(i, j)
					+ k6 * tempiamge.getPixel(i + 1, j)
					+ k7 * tempiamge.getPixel(i - 1, j + 1)
					+ k8 * tempiamge.getPixel(i, j + 1)
					+ k9 * tempiamge.getPixel(i + 1, j + 1);
				float tmp = s / ksum;
				
				tempiamges.setPixel(i, j, (tempiamge.getPixel(i, j) - tmp));
			}
		}

		//ImageIO::showImage(image);
	ImageIO::showImage(tempiamges);
	IntensityImageStudent tempiamgesh(tempiamges);

	for (int i = 0; i < tempiamges.getWidth(); ++i){
		for (int j = 0; j < tempiamges.getHeight(); ++j){
			//int tmp = image.getPixel(i, j);
			int s = k1sh * tempiamges.getPixel(i - 1, j - 1)
				+ k2sh * tempiamges.getPixel(i, j - 1)
				+ k3sh * tempiamges.getPixel(i + 1, j - 1)
				+ k4sh * tempiamges.getPixel(i - 1, j)
				+ k5sh * tempiamges.getPixel(i, j)
				+ k6sh * tempiamges.getPixel(i + 1, j)
				+ k7sh * tempiamges.getPixel(i - 1, j + 1)
				+ k8sh * tempiamges.getPixel(i, j + 1)
				+ k9sh * tempiamges.getPixel(i + 1, j + 1);
			//float tmp = s / ksumsh;

			tempiamgesh.setPixel(i, j, s);
		}
	}*/
	//..ImageIO::showImage(tempiamgesh);
	//ImageIO::showImage(image);
	//std::cout << features;
	IntensityImageStudent tempimage(image);

	Point2D<double> headLeftPoint = features.getFeature(Feature::FEATURE_HEAD_LEFT_NOSE_BOTTOM).getPoints()[0];
	Point2D<double> headRightPoint = features.getFeature(Feature::FEATURE_HEAD_RIGHT_NOSE_BOTTOM).getPoints()[0];

	Point2D<double> noseEndLeft = features.getFeature(Feature::FEATURE_NOSE_END_LEFT).getPoints()[0];
	Point2D<double> noseEndRight = features.getFeature(Feature::FEATURE_NOSE_END_RIGHT).getPoints()[0];

	Point2D<double> noseBottom = features.getFeature(Feature::FEATURE_NOSE_BOTTOM).getPoints()[0];
	int headWidth = (int)(headRightPoint.getX() - headLeftPoint.getX());

	/*for (int i = -5; i < 5; i++) {
		for (int j = -5; j < 5; j++) {
			tempimage.setPixel(headLeftPoint.getX() + i, headLeftPoint.getY() + j, 128);
		}
	}

	for (int i = -5; i < 5; i++) {
		for (int j = -5; j < 5; j++) {
			tempimage.setPixel(headRightPoint.getX() + i, headRightPoint.getY() + j, 128);
		}
	}

	for (int i = -5; i < 5; i++) {
		for (int j = -5; j < 5; j++) {
			tempimage.setPixel(noseEndLeft.getX() + i, noseEndLeft.getY() + j, 128);
		}
	}

	for (int i = -5; i < 5; i++) {
		for (int j = -5; j < 5; j++) {
			tempimage.setPixel(noseEndRight.getX() + i, noseEndRight.getY() + j, 128);
		}
	}

	for (int i = -5; i < 5; i++) {
		for (int j = -5; j < 5; j++) {
			tempimage.setPixel(noseBottom.getX() + i, noseBottom.getY() + j, 128);
		}
	}*/

	int abovenose = noseBottom.getY() - (headWidth / 2.5);

	/*for (int i = -5; i < 5; i++) {
	for (int j = -5; j < 5; j++) {
	tempimage.setPixel(headLeftPoint.getX() + i, abovenose + j, 40);
	}
	}

	for (int i = -5; i < 5; i++) {
	for (int j = -5; j < 5; j++) {
	tempimage.setPixel(headRightPoint.getX() + i, abovenose + j, 40);
	}
	}

	for (int i = -5; i < 5; i++) {
	for (int j = -5; j < 5; j++) {
	tempimage.setPixel(headRightPoint.getX() + i, (abovenose - headWidth/2) + j, 40);
	}
	}

	for (int i = -5; i < 5; i++) {
	for (int j = -5; j < 5; j++) {
	tempimage.setPixel(headLeftPoint.getX() + i, (abovenose - headWidth/2) + j, 40);
	}
	}*/
	int widthf = headRightPoint.getX() - headLeftPoint.getX();
	int heightf = abovenose - (abovenose - (headWidth / 2));

	std::cout << widthf << " " << heightf << "\n";

	IntensityImageStudent test;
	test.set(widthf, heightf);
	std::cout << headLeftPoint.getX() << " " << headRightPoint.getX() << "\n";
	std::cout << (abovenose - (headWidth/2)) << " " << headLeftPoint.getX() << "\n";
	
	for (int i = headLeftPoint.getX(); i < headRightPoint.getX(); i++) {
		for (int j = (abovenose - (headWidth /2)); j < abovenose; j++){
			tempimage.setPixel(i,j, 40);
			test.setPixel(i - headLeftPoint.getX(), j - (abovenose - (headWidth / 2)), image.getPixel(i, j));
		}
	}
	//ImageIO::showImage(test);
	IntensityImageStudent subset(test);
	
	//std::cout << headLeftPoint.getX() << "\n";
	//std::cout << headRightPoint << "\n";
	int k1 = 0, k2 = 1, k3 = 0,
		k4 = 1, k5 = 1, k6 = 1,
		k7 = 0, k8 = 1, k9 = 0;
	int ksum = (k1 + k2 + k3 + k4 + k5 + k6 + k7 + k8 + k9);
	
	for (int i = 0; i < test.getWidth(); ++i){
		for (int j = 0; j < test.getHeight(); ++j){
			//int tmp = image.getPixel(i, j);
			int s = k1 * test.getPixel(i - 1, j - 1)
				+ k2 * test.getPixel(i, j - 1)
				+ k3 * test.getPixel(i + 1, j - 1)
				+ k4 * test.getPixel(i - 1, j)
				+ k5 * test.getPixel(i, j)
				+ k6 * test.getPixel(i + 1, j)
				+ k7 * test.getPixel(i - 1, j + 1)
				+ k8 * test.getPixel(i, j + 1)
				+ k9 * test.getPixel(i + 1, j + 1);
			float tmp = s / ksum;

			subset.setPixel(i, j, s);
		}
	}
	ImageIO::showImage(subset);
	IntensityImageStudent hist;
	hist.set(subset.getWidth(), 400);


	//ImageIO imageshower;
	//imageshower.showImageaa(subset);
	//ImageIO::showImage(subset, "testwindow");
	IntensityImageStudent showwhere(subset);
	int* testarray = new int[subset.getWidth()];
	int sum = 0;
	for (int j = 0; j < test.getHeight(); ++j){
		showwhere.set(subset);
		for (int i = 0; i < subset.getWidth(); ++i){
			showwhere.setPixel(i,j,0);
			testarray[i] = subset.getPixel(i, j);
			sum += subset.getPixel(i, j);
			for (int z = 0; z < hist.getHeight(); z++) {
				hist.setPixel(i,z,255);
			}
			//std::cout << "pixsel " << (int)subset.getPixel(i, j) << "\n";
			hist.setPixel(i, 50 +subset.getPixel(i, j),0);
		}
		sum /= subset.getWidth();
		std::cout << "y " << j  << "\n";
		sum = 0;

		ImageIO::showImage(showwhere, "dd");
		ImageIO::showImage(hist);
	}

	delete testarray;
	

	//ImageIO::showImage(image);
	ImageIO::showImage(subset);
	//ImageIO::showImage(test);
	
	return false;
}