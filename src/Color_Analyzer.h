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

#define NBR_OF_COLOR 9

#define NBR_OF_COLOR 10
enum T_COLOR{
	BLACK,
	GREY,
	WHITE,
	RED,
	ORANGE,
	YELLOW,
	GREEN,
	CYAN,
	BLUE,
	MAGENTA
};

//-----------------------------------------------------------------------
//------------------------------ Functions ------------------------------
//-----------------------------------------------------------------------



namespace wm_color_analyser{
	void PrintVersion();

	std::string LoadAnImageFromCVMat(cv::Mat image, int x1, int x2, int y1, int y2);

	T_COLOR getColorID(int hue, int saturation, int value);

	std::string getColorName(int color);

	void getColorValue(int colors[NBR_OF_COLOR], cv::Mat image_hsv, int x1, int x2, int y1, int y2);
}

#endif //PROJECT_COLOR_ANALYZER_H

