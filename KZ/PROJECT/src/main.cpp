#include <iostream>
#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main()
{
    std::cout << "Hello World." << std::endl;
    cv::Mat image = cv::imread("/home/hzarkov/Desktop/Tonji/dataset/images/900_bdd.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        std::cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    
    // cv::cvtColor(image, image, CV_RGB2GRAY);
    
    int thresh = 100;

    cv::Mat canny_output;
    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;

    /// Detect edges using canny
    cv::Canny( image, canny_output, thresh, thresh*2, 3 );

    cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );// Create a window for display.
    cv::imshow("Display window", canny_output);
    cv::waitKey(0);
    return 0;
}