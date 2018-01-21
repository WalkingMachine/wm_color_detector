//
// Created by lucas on 15/10/17.
//

#include "ColorationAnalyser.h"

/**
 * Service method
 * @param req
 * @param res
 * @return
 */
bool get_bounding_boxes_color(wm_color_detector::AnalyseColor::Request &req, wm_color_detector::AnalyseColor::Response &res){
	// TODO: Implemente try catch

	// Read the image and convert then to a CV image pointer
	cv_bridge::CvImagePtr ptr = cv_bridge::toCvCopy(req.image, sensor_msgs::image_encodings::BGR8);

	// Execute the analyse for all bounding boxes
	for (auto &boundingBoxe : req.boundingBoxes) {
		// Create a color message
		wm_color_detector::Coloration color;

		// Execute the analysis
		color.color = LoadAnImageFromCVMat(ptr->image, boundingBoxe.xmin, boundingBoxe.xmax, boundingBoxe.ymin,
		                                   boundingBoxe.ymax);
		// Add the result to the result answers
		res.colors.push_back(color);
	}
	return true;
}

int main(int argc, char **argv) {
	// Initialise ROS
	ros::init(argc, argv, "wm_coloration_analyser");
	ros::NodeHandle n;

	// Advertise the service
	ros::ServiceServer service = n.advertiseService("get_bounding_boxes_color", get_bounding_boxes_color);

	// LOOP
	ros::spin();

	return 0;
}