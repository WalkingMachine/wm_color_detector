//
// Created by lucasmaurice on 15/10/17.
//

#ifndef PROJECT_COLOR_ANALYZER_H
#define PROJECT_COLOR_ANALYZER_H

// Include for OpenCV
#include <cv_bridge/cv_bridge.h>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

// Include for print
#include <sstream>
#include <string.h>



//-----------------------------------------------------------------------
//------------------------------- Colors --------------------------------
//-----------------------------------------------------------------------

#define WHITE_THRESHOLD 200
#define BLACK_THRESHOLD 50
#define MONOCHROME_THRESHOLD 20

#define NBR_OF_COLOR 9

enum T_COLOR{
	BLACK,
	GREY,
	WHITE,
	RED,
	YELLOW,
	GREEN,
	CYAN,
	BLUE,
	MAGENTA
};

//-----------------------------------------------------------------------
//------------------------------ Functions ------------------------------
//-----------------------------------------------------------------------

/**
 * Print the version of OpenCV
 */
void PrintVersion();

std::string LoadAnImageFromCVMat(cv::Mat image, int x1, int x2, int y1, int y2);

T_COLOR getColorID(int hue, int saturation, int value);

std::string getColorName(int color);

void getColorValue(int colors[NBR_OF_COLOR], cv::Mat image_hsv, int x1, int x2, int y1, int y2);

#endif //PROJECT_COLOR_ANALYZER_H

