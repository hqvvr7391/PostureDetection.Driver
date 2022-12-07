#include <iostream>
#include <opencv2/opencv.hpp>
//#include <P:/Frameworks/Library/Graphics/opencv/build/include/opencv2/opencv.hpp>

int main(int, char**) {
    std::cout << "Hello, world!\n";
    std::cout << "Hello, world!\n";

    cv::Mat test(320, 240, CV_8UC3, cv::Scalar(0, 0, 0));
    cv::imshow("stest", test);

    cv::waitKey(0);

}

