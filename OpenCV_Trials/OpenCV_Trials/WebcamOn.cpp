#include "OpenCV_Trials.h"

using namespace std;
using namespace cv;


int WebcamOn(int argc, char** argv)
{
    VideoCapture cap(0);
    
    Mat frame;

    float fps = 0.0;
    double prev = clock();
    while (true)
    {
        auto n = std::chrono::system_clock::now();

        //double now = (clock() / (double)clocks_per_sec);
        //fps = (fps * fps_smoothing + (1 / (now - prev)) * (1.0 - fps_smoothing));
        //prev = now;

        //printf("fps: %.1f\n", fps);

        //for (double i = 1; i <= 1000000000; i++);

        if (cap.isOpened()) {
            cap.read(frame);
        }
        imshow("asdf", frame);

        auto m = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = m - n;
        double d = elapsed.count();
        cout << "frames per second : " << (double)(1 / d) << endl;
        if (waitKey(2) == 27) {
            break;
        }
    }
    return 0;
}