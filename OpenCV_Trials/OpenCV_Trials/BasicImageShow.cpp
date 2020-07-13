#include "FunctionDeclarations.h"

using namespace std;
using namespace cv;

int ImageShow()
{
    // Read the image file
    Mat image = imread("C:/Users/dhiro/OneDrive/Pictures/Screenshots/Input to warp.png");

    if (image.empty()) // Check for failure
    {
        cout << "Could not open or find the image" << endl;
        system("pause"); //wait for any key press
        return -1;
    }


    /**
    Btw This can also be done
    while (cv::waitKey(30) < 0)
    {
        cv::imshow("OpenCV output :", image);
    }
    */

    String windowName = "My HelloWorld Window"; //Name of the window

    namedWindow(windowName, WINDOW_AUTOSIZE); // Create a window

    imshow(windowName, image); // Show our image inside the created window.

    waitKey(0); // Wait for any keystroke in the window

    destroyWindow(windowName); //destroy the created window

    return 0;
}