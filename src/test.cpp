//
// Created by lucas on 15/10/17.
//

#include "test.h"

int main(int argc, char **argv) {
	// Initialise ROS connection
	ros::init(argc, argv, "test_ros");
	ros::NodeHandle n;

	PrintVersion();

	LoadAnImage();

	return 0;
}