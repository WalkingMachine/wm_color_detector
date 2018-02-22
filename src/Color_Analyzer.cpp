//
// Created by lucasmaurice on 15/10/17.
//

#include "Color_Analyzer.h"

/**
 * Print the version of OpenCV
 */
void PrintVersion() {
	std::cout << "OpenCV version : " << CV_VERSION << std::endl;
	std::cout << "Major version : " << CV_MAJOR_VERSION << std::endl;
	std::cout << "Minor version : " << CV_MINOR_VERSION << std::endl;
	std::cout << "Subminor version : " << CV_SUBMINOR_VERSION << std::endl;
}

/**
 * Analyse the color of an image
 * @param image 	The image matrix
 * @param x1		first point x
 * @param x2 		last point x
 * @param y1 		first point y
 * @param y2 		lastpoint y
 * @return 			color string
 */
std::string LoadAnImageFromCVMat(cv::Mat image, int x1, int x2, int y1, int y2){
	int colors[NBR_OF_COLOR];
	cv::Mat image_hsv;
	std::string colour = "unknown";
	int max = 0;

	//Calculate the number of pixels
	int nbr_pixel = (x2 - x1) * (y2 - y1);

	// If there is at least one pixel, filter the color counter
	if(nbr_pixel > 0) {

		// Convert the image from RGB to HSH
		cv::cvtColor(image, image_hsv,CV_RGB2HSV);

		// Count the number of pixels for each colors
		getColorValue(colors, image_hsv, x1, x2, y1, y2);

		// For each color, print the number of pixels and the percentage
		for (int color = 0; color < NBR_OF_COLOR; color++) {

			// Print the color
			std::cout << getColorName(color) << "\t: " << colors[color] * 100 / nbr_pixel << "\t" << "% (" << colors[color] << ")"<< std::endl;

			//Get the most important one
			if (colors[color] > max) {
				max = colors[color];
				colour = getColorName(color);
			}
		}
	}
	std::cout << "main color: " << colour << std::endl;
	return colour;
}

/**
 *
 * @param colors 	pointer to the colors array
 * @param image_hsv the image matrix in hsv
 * @param x1		first point x
 * @param x2 		last point x
 * @param y1 		first point y
 * @param y2 		lastpoint y
 */
void getColorValue(int colors[], cv::Mat image_hsv, int x1, int x2, int y1, int y2){
	cv::Vec3b hsv;
	int H;
	int S;
	int V;

	// Initialise the list
	for(int color = 0; color < NBR_OF_COLOR; color ++){
		colors[color] = 0;
	}

	// For each pixels, read the color id
	for(int x_pos = x1; x_pos < x2 ; x_pos++){
		for(int y_pos = y1; y_pos < y2 ; y_pos++) {
			hsv=image_hsv.at<cv::Vec3b>(y_pos,x_pos);

			H = hsv.val[0] * 2; //hue
			S = hsv.val[1]; //saturation
			V = hsv.val[2]; //value

			// Increment the number of pixel of the selected color
			colors[getColorID(H, S, V)] ++;
		}
	}
}

/**
 * Get the color in a pixel
 * @param hue 			value of the hue
 * @param saturation 	value of the saturation
 * @param value 		value of the intensity
 * @return 				ID of the color
 */
T_COLOR getColorID(int hue, int saturation, int value){

	//std::cout << value << std::endl;
	// Assume it is black
	if(value < BLACK_THRESHOLD){
		return BLACK;
	}

	// Assume it is monochrome
	if( saturation < MONOCHROME_THRESHOLD ){

		// Assume it is white
		if(value > WHITE_THRESHOLD){
			return WHITE;
		}
		// Assume it is grey
		else {
			return GREY;
		}
	}
	// Assume it is chromatic
	else{

		// For each colors
		if ((0 < hue) && (hue <= 10)){
			return RED;
		}else if ((10 < hue) && (hue <= 30)){
			return ORANGE;
		}else if ((30 < hue) && (hue <= 60)){
			return YELLOW;
		}else if ((60 < hue) && (hue <= 150)){
			return GREEN;
		}else if ((150 < hue) && (hue <= 210)){
			return CYAN;
		}else if ((210 < hue) && (hue <= 270)){
			return BLUE;
		}else if ((270 < hue) && (hue <= 330)){
			return MAGENTA;
		}else if ((330 < hue) && (hue <= 360)){
			return RED;
		}
	}
	// In all others cases
	return BLACK;
}

/**
 * Get the string value of a color ID
 * @param color
 * @return
 */
std::string getColorName(int color) {
	switch(color){
		case BLACK:
			return  "Black";
		case GREY:
			return  "Grey";
		case WHITE:
			return  "White";
		case RED:
			return  "Red";
		case ORANGE:
			return  "Orange";
		case YELLOW:
			return  "Yellow";
		case GREEN:
			return  "Green";
		case CYAN:
			return  "Cyan";
		case BLUE:
			return  "Blue";
		case MAGENTA:
			return  "Magenta";
		default:
			return  "Unknown";
	}
}
