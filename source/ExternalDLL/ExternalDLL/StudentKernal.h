#pragma once
#include "IntensityImage.h"
#include "IntensityImageStudent.h"

class StudentKernal {
public:
	static IntensityImageStudent * applyKernal(const IntensityImage &image, int mask[3][3], bool div = false, bool sub = false);
};