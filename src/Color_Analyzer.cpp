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

void LoadAnImage() {
	cv::Mat image;

	int colors[NBR_OF_COLOR];
	image = cv::imread("/home/lucas/Documents/red.png", CV_LOAD_IMAGE_COLOR);   // Read the file

	// Check for invalid input
	if(! image.data ){
		std::cout <<  "Could not open or find the image" << std::endl ;
	}

	std::cout << "Img size : " << image.cols << "x" << image.rows << std::endl;

	cv::Mat image_hsv;

	cv::cvtColor(image, image_hsv,CV_BGR2HSV);
	cv::Vec3b hsv;
	cv::Vec3b rgb;

	getColorValue(colors, image_hsv, 0, 100, 0, 100);
	int nbr_pixel = 100;
	for(int color = 0; color < NBR_OF_COLOR; color ++){
		std::cout << getColorName(color) << "\t: " << colors[color]/nbr_pixel << "\t" << "%" << std::endl;
	}
}

std::string LoadAnImageFromCVMat(cv::Mat image, int x1, int x2, int y1, int y2){
	int colors[NBR_OF_COLOR];
	cv::Mat image_hsv;

	std::string colour = "unknown";
	int max = 0;

	cv::cvtColor(image, image_hsv,CV_BGR2HSV);
	cv::Vec3b hsv;
	cv::Vec3b rgb;

	getColorValue(colors, image_hsv, x1, x2, y1, y2);

	int nbr_pixel = (x2 - x1) * (y2 - y1);

	//std::cout << x1 << " " << x2 << " " << y1 << " " << y2 << "end:" << nbr_pixel << std::endl;

	if(nbr_pixel > 0) {
		for (int color = 0; color < NBR_OF_COLOR; color++) {
			std::cout << getColorName(color) << "\t: " << colors[color] * 100 / nbr_pixel << "\t" << "% (" << colors[color] << ")"<< std::endl;
			if (colors[color] > max) {
				max = colors[color];
				colour = getColorName(color);
			}
		}
	}
	std::cout << "main color: " << colour << std::endl;
	return colour;
}

void getColorValue(int colors[], cv::Mat image_hsv, int x1, int x2, int y1, int y2){
	cv::Vec3b hsv;
	int H;
	int S;
	int V;

	for(int color = 0; color < NBR_OF_COLOR; color ++){
		colors[color] = 0;
	}

	for(int x_pos = x1; x_pos < x2 ; x_pos++){
		for(int y_pos = y1; y_pos < y2 ; y_pos++) {
			hsv=image_hsv.at<cv::Vec3b>(y_pos,x_pos);

			H = hsv.val[0] * 2; //hue
			S = hsv.val[1]; //saturation
			V = hsv.val[2]; //value

			colors[getColorID(H, S, V)] ++;
//			colors[getColorID(H, S, V)] = 100;
		}
	}
}

T_COLOR getColorID(int hue, int saturation, int value){

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
		if((0 <= hue) && (hue <= 30)){
			return RED;
		}else if ((30 < hue) && (hue <= 90)){
			return YELLOW;
		}else if ((90 < hue) && (hue <= 150)){
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
	return BLACK;
}

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
