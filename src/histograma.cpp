/*************************
        histograma
**************************/

// C++ program to implement the erosion
// and dilation
#include <iostream>
#include <opencv2/core/core.hpp>
#include "functions.h"
// Library to include for drawing shapes
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;
using namespace std;

funciones fun;


// Driver Code
int main(int argc, char** argv)
{
    // Reading the Image
    Mat image = imread("/home/y3rsn/Dev/cpp/CV_2022/opencv_basic/road.jpg",IMREAD_GRAYSCALE);

    imshow("original",fun.ResizeImage(image,0.3));

    // Check if the image is created
    // successfully or not
    if (!image.data) {
        std::cout << "Could not open or find"
                  << " the image\n";
        return 0;
    }

    // Create a structuring element (SE)
    int morph_size = 2;
    Mat element = getStructuringElement(
        MORPH_RECT, Size(2 * morph_size + 1,
                         2 * morph_size + 1),
        Point(morph_size, morph_size));
    Mat erod, dill;

    // For Erosion
    erode(image, erod, element,
          Point(-1, -1), 1);

    // For Dilation
    dilate(image, dill, element,
           Point(-1, -1), 1);

    // Display the image
    imshow("source", fun.ResizeImage(image,0.3));
    imshow("erosion", fun.ResizeImage(erod,0.3));
    imshow("dilate", fun.ResizeImage(dill,0.3));
    waitKey();

    return 0;
}
