#include "OpenCV_Trials.h"
#include <chrono>
#include <vector>
#include <numeric>



using namespace std;
using namespace cv;

int FaceDetector(int argc, char** argv)
{
	auto color = Scalar(0, 0, 120);
	namedWindow("video", WINDOW_NORMAL);
	//Mat loading = imread("C:/Users/dhiro/source/repos/TrialStuff/OpenCV_Trials/OpenCV_Trials/loading_img.png");
	//imshow("video", loading);
	Mat cross = imread("C: / Users / dhiro / source / repos / TrialStuff / OpenCV_Trials / OpenCV_Trials / cross.png");

	CascadeClassifier faceCascade;

	faceCascade.load("C:\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_default.xml");

	VideoCapture cap(0);

	cap.set(3, 640);
	cap.set(3, 480);
	Size original(640, 480);

	vector<double> fps;

	while (true)
	{
		Size win(200,150);
		auto n = std::chrono::system_clock::now();

		Mat img;

		cap.read(img);
		Mat copy = img.clone();

		resize(img, img, win);
		
		Mat gray;
		cvtColor(img, gray, COLOR_BGR2GRAY);
		vector<Rect> faces;

		faceCascade.detectMultiScale(
			gray,
			faces,
			1.2,
			5,
			0,
			Size(20, 20)
		);

		for (auto face = faces.begin(); face != faces.end(); ++face)
		{
			auto rect_O = face->tl();
			auto rect_D = face->br();
			

			//cout << rect_O << "    " << rect_D << "   -------------->>   ";

			//rectangle(img, rect_O, rect_D, Scalar(255, 0, 0), 1);

			rect_O = translate(rect_O, win, original);
			rect_D = translate(rect_D, win, original);

			//cout << rect_O << "    " << rect_D << endl;

			rectangle(copy, rect_O, rect_D , Scalar(0, 0, 255), 0);
			

			// now we draw a cross
			//line(copy, rect_O, rect_D, color, 5);
			//line(copy, Point(rect_D.x, rect_O.y), Point(rect_O.x, rect_D.y), color, 5);
			

		}


		imshow("video", copy);
		//imshow("original", img);

		auto m = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed = m - n;
		double d = 1 / elapsed.count();
		//cout << "frames per second : " << d << endl;
		fps.push_back(d);

		if (waitKey(10) == 27)
		{
			break;
		}
		
	}

	double avg_fps = accumulate(fps.begin(), fps.end(), 0) / fps.size();
	cout << "Average FPS :"<< avg_fps << endl;
	return 0;
}

