#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

int main()
{
    std::string image_path = "../test_image.png";
    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
    if (img.empty())
    {

        std::cout << "Could not read the image" << std::endl;
        return 1;
    }
    else
    {
        cv::imshow("Display window", img);
        int k = cv::waitKey(0);
    }
    return 0;
}
