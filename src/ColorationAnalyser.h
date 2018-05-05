//
// Created by lucas on 15/10/17.
//

#ifndef PROJECT_TEST_H
#define PROJECT_TEST_H

#include "Color_Analyzer.h"

#include <cv_bridge/cv_bridge.h>
#include <std_msgs/String.h>

// Includes for ROS
#include "ros/ros.h"
#include "wm_color_detector/AnalyseColor.h"
#include "sara_msgs/BoundingBoxes2D.h"


namespace wm_color_analyser{
	bool get_bounding_boxes_color(wm_color_detector::AnalyseColor::Request &req, wm_color_detector::AnalyseColor::Response &res);
	int init(int argc, char **argv);
}

#endif //PROJECT_TEST_H
