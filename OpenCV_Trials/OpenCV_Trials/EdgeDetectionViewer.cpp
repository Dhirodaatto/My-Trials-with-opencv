
#include "OpenCV_Trials.h"

using namespace cv;


static void CannyThreshold(int, void*)
{
    blur(src_gray, detected_edges, Size(3, 3));

    Canny(detected_edges, detected_edges, lowThreshold, lowThreshold * ratio, kernel_size);
    dst = Scalar::all(0);
    src.copyTo(dst, detected_edges);
    imshow(window_name, dst);
}


int CreateEdgeDetectionViewer(int argc, char** argv)
{
    String imageName("C:/Users/dhiro/OneDrive/Pictures/Camera Roll/img2.jpg"); // by default
    if (argc > 1)
    {
        imageName = argv[1];
    }

    src = imread(samples::findFile(imageName), IMREAD_COLOR);

    if (src.empty())
    {
        std::cout << "Could not open or find the image!\n" << std::endl;
        std::cout << "Usage: " << argv[0] << " <Input image>" << std::endl;
        return -1;
    }
    dst.create(src.size(), src.type());
    cvtColor(src, src_gray, COLOR_BGR2GRAY);
    namedWindow(window_name, WINDOW_AUTOSIZE);
    createTrackbar("Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold);
    CannyThreshold(0, 0);
    waitKey(0);
    return 0;
}