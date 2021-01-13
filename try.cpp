#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{  
    Mat image = imread("image.jpg", IMREAD_UNCHANGED);
    Mat temp;
    if (image.empty())
    {
        cout << "ERROR";
        cin.get();
        return -1;
    }
    int angle;
    cout << "\nEnter the angle : ";
    cin >> angle;
    string direction;
    cout << "\nEnter the direction: (C for Clockwise AND A for Anti-clockwise) : ";
    cin >> direction;
    if (direction == "C"|| direction == "c")
    {
        angle = -angle;
    }
    Point2f image_center((image.cols-1) / 2.0F, (image.rows-1) / 2.0F);
    Mat i = getRotationMatrix2D(image_center,angle, 1.0);
    Rect2f img = RotatedRect(Point2f(), image.size(), angle).boundingRect2f();
    i.at<double>(0, 2) += img.width / 2.0 - image.cols / 2.0;
    i.at<double>(1, 2) += img.height / 2.0 - image.rows / 2.0;
    warpAffine(image, temp, i, img.size());
    string window = "Original Flower";
    namedWindow(window, WINDOW_NORMAL);
    imshow(window, image);
    waitKey(0);
    window = "Rotated Flower";
    namedWindow(window, WINDOW_NORMAL);
    imshow(window,temp);
    waitKey(0);
    destroyWindow(window);
}
