//
// Created by lucasmaurice on 15/10/17.
//

#include "Color_Analyzer.h"

/**
 * Print the version of OpenCV
 */
void PrintVersion() {
	cout << "OpenCV version : " << CV_VERSION << endl;
	cout << "Major version : " << CV_MAJOR_VERSION << endl;
	cout << "Minor version : " << CV_MINOR_VERSION << endl;
	cout << "Subminor version : " << CV_SUBMINOR_VERSION << endl;
}

void LoadAnImage() {
	Mat image;

	int colors[NBR_OF_COLOR];
	image = imread("/home/lucas/Documents/red.png", CV_LOAD_IMAGE_COLOR);   // Read the file

	// Check for invalid input
	if(! image.data ){
		cout <<  "Could not open or find the image" << endl ;
	}

	cout << "Img size : " << image.cols << "x" << image.rows << endl;

	Mat image_hsv;

	cvtColor(image, image_hsv,CV_BGR2HSV);
	Vec3b hsv;
	Vec3b rgb;

	getColorValue(colors, image_hsv, 0, 100, 0, 100);
	//getColorValue(colors, image_hsv, 124, 470, 215, 594);
}

void getColorValue(int colors[NBR_OF_COLOR], Mat image_hsv, int x1, int x2, int y1, int y2){
	Vec3b hsv;
	int H;
	int S;
	int V;

	int nbr_pixel = (x2 - x1) * (y2 - y1) / 100;

	for(int color = 0; color < NBR_OF_COLOR; color ++){
		colors[color] = 0;
	}

	for(int x_pos = x1; x_pos < x2 ; x_pos++){
		for(int y_pos = y1; y_pos < y2 ; y_pos++) {
			hsv=image_hsv.at<Vec3b>(y_pos,x_pos);

			H = hsv.val[0] * 2; //hue
			S = hsv.val[1]; //saturation
			V = hsv.val[2]; //value

			//cout << H << endl;

			colors[getColorID(H, S, V)] ++;
		}
	}

	for(int color = 0; color < NBR_OF_COLOR; color ++){
		cout << getColorName(color) << "\t: " << colors[color]/nbr_pixel << "\t" << "%" << endl;
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
	}

	return std::__cxx11::string();
}
