#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <Windows.h> //used for Function HideConsole()
// following inclusions are for WebcamOn
#include <stdint.h>
#include <chrono>
#include <ctime>
// inclusions for webcam: end
using namespace cv;


const double aspect_ratio = 4 / 3;

//========================================================================================================
//All general functions
void HideConsole();
//========================================================================================================


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// ColorSlideViewer

//variables 
const int max_color_value = 255;
static int red_value = 0;
static int green_value = 0;
static int blue_value = 0;
static const char* color_slide_viewer = "Color slider";
static Mat init_color(600, 800, CV_8UC3, Scalar(0,0,0));

//functions 
static void redChange(int, void*);
static void greenChange(int, void*);
static void blueChange(int, void*);
 int ColorSlider_main(int argc, char** argv);

// =======================================================================================================

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// EdgeDetectionViewer

//Variables
 static Mat src, src_gray;
 static Mat dst, detected_edges;
 static int lowThreshold = 0;
 static const int max_lowThreshold = 500;
 static const int ratio = 3;
 static const int kernel_size = 3; // this variable should be b/w 3 and 7 otherwise runtime error
 static const char* window_name = "Edge Map";

// functions
 static void CannyThreshold(int, void*);
 int CreateEdgeDetectionViewer(int argc, char** argv);

 //===================================================================================================================

 //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 // WebcamOn function

 int WebcamOn(int argc, char** argv);

 //===================================================================================================================

 //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 // FaceDetector

 int FaceDetector(int, char**);
Point2i translate(Point2i, Size, Size);

 //==================================================================================================================