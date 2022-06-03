#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int dilation_size = 2;
int const max_kernel_size = 21;

void Dilation( int, void* );


cv::Mat dilatacion(cv::Mat image)
{
  cv::Mat out,dilation_dst;
  int dilation_type = dilation_type = MORPH_RECT;

  Mat element = getStructuringElement(
      dilation_type,Size( 2*dilation_size + 1, 2*dilation_size+1 ),
      Point( dilation_size, dilation_size ) );

  dilate( image, dilation_dst, element );
  imshow( "Dilation Demo", dilation_dst );

  return out;
}

int main( int argc, char** argv )
{
  //cv::Mat src = imread("/home/y3rsn/Dev/cpp/CV_2022/Roadtraking/img/road_canny.png", IMREAD_COLOR );
  cv::Mat src = imread("/home/y3rsn/Dev/cpp/CV_2022/Roadtraking/img/road.jpeg", IMREAD_GRAYSCALE );
  if( src.empty() )
  {
    cout << "Could not open or find the image!\n" << endl;
    cout << "Usage: " << argv[0] << " <Input image>" << endl;
    return -1;
  }

  dilatacion(src);

  waitKey(0);
  return 0;
}


