#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

int main()
{
    std::string image_path = "../test_image.png";
    cv::Mat img = cv::imread(image_path);

    if (img.empty())
    {
        std::cerr << "Error Reading The Image!" << image_path << std::endl;
        return 1;
    }

    cv::line(img, cv::Point(0, 0), cv::Point(img.cols, img.rows), cv::Scalar(0, 255, 0), 3);
    cv::rectangle(img, cv::Point(100, 50), cv::Point(300, 200), cv::Scalar(255, 0, 0), 5);
    cv::Point center = cv::Point(img.cols / 2, img.rows / 2);
    int radius = 100;
    cv::circle(img, center, radius, cv::Scalar(0, 0, 255), -1);
    cv::putText(img, "OpenCV drawing", cv::Point(10, 20), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 255, 255), 2);

    cv::namedWindow("Edited Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Edited Image", img);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}