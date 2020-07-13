#include "OpenCV_Trials.h"

using namespace std;
using namespace cv;


Point2i translate(Point2i p, Size prev, Size nex)
{
    Point2i translated;

    double a = (((double)p.x / (double)prev.width)* (double)nex.width);
    double b = (((double)p.y / (double)prev.height) *(double)nex.height);
    
    translated.x = (int)a;
    translated.y = (int)b;
    
    //cout << a << ", " << b << endl;

    return translated;
}