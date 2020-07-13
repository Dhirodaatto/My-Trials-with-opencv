#include "OpenCV_Trials.h"

using namespace cv;

static void redChange(int, void*)
{
	Mat init_color(600, 800, CV_8UC3, Scalar(blue_value, green_value, red_value));
	imshow(color_slide_viewer, init_color);
}

static void greenChange(int, void*)
{
	Mat init_color(600, 800, CV_8UC3, Scalar(blue_value, green_value, red_value));
	imshow(color_slide_viewer, init_color);
}

static void blueChange(int, void*)
{
	Mat init_color(600, 800, CV_8UC3, Scalar(blue_value, green_value, red_value));
	imshow(color_slide_viewer, init_color);
}


int ColorSlider_main(int argc, char** argv)
{
	//HideConsole();

	if (init_color.empty())
	{
		std::cout << "Something went wrong ... " << std::endl;
		return -1;
	}

	namedWindow(color_slide_viewer, WINDOW_NORMAL);
	createTrackbar(" Red ", color_slide_viewer, &red_value, max_color_value, redChange);
	createTrackbar(" Green ", color_slide_viewer, &green_value, max_color_value, greenChange);
	createTrackbar(" Blue ", color_slide_viewer, &blue_value, max_color_value, blueChange);
	redChange(0, 0);
	blueChange(0, 0);
	greenChange(0, 0);
	waitKey(0);
	return 0;
}