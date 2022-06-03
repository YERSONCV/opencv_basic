#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "functions.h"
// best canny value 62

funciones fun;

cv::Mat bordes(Mat image)
{
    Mat gray,canny,dst;
    cvtColor(image,gray,COLOR_BGR2GRAY);
    blur(gray,canny,cv::Size(3,3));

    cv::Mat out;

    Canny(canny,out,62,62*3,3);
    dst.create(image.size(), image.type());
    //imshow("gray image",gray);
   return out;
}

int main()
{
    cv::Mat src = cv::imread("/home/y3rsn/Dev/cpp/CV_2022/Roadtraking/img/road.jpeg");

     if (src.empty())
     {
	return -1;
     }
	
     cv::Mat result = bordes(src);

     cv::imshow("result",result);

     cv::waitKey(0);
     destroyAllWindows();
   return 0;
}

