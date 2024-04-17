#include <opencv2/opencv.hpp>

#include <iostream>
#include <string>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    // Read file
    Mat image = imread("/Man walking");

    if (image.empty())
    {
        cout << "Image loading has failed" << endl;
        system("pause");
        return -1;
    }

    // Display file
    String windowName = "Image Display";
    namedWindow(windowName, WINDOW_AUTOSIZE);
    imshow(windowName, image);

    waitKey(0); // wait for a key in the window

    // Gray scale
    Mat grayImage;

    cvtColor(image, grayImage, COLOR_BGR2GRAY);

    namedWindow("Gray Image", WINDOW_AUTOSIZE);
    imshow("Gray Image", grayImage);
    waitKey(0);

    // Circle
    Point center(100, 100);
    int radius = 100;
    Scalar line_Color(255, 255, 255);
    int thickness = 2;

    // Draw circles
    circle(grayImage, center, radius, line_Color, thickness);

    waitKey(0); // wait for a key in the window

    // Destroy
    destroyWindow(windowName);
    destroyWindow(grayImage);
    image.release();
    grayImage.release();

    return 0;
}