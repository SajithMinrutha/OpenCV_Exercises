#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

int main()
{
    std::string image_path = "../test_image.png";
    cv::Mat image = cv::imread(image_path);
    if (image.empty())
    {
        std::cerr << "Failed To Load The Image" << std::endl;
    }

    // cropping
    cv::Rect roi(100, 50, 200, 150);
    cv::Mat cropped_image = image(roi);

    // resizing
    cv::Mat resized_image;
    cv::resize(image, resized_image, cv::Size(300, 250), 0, 0, cv::INTER_LINEAR);

    // rotating
    cv::Mat rotated_image;
    cv::Point2f center(image.cols / 2.0, image.rows / 2.0);
    double angle = 45.0;
    double scale = 1.0;
    cv::Mat rot = cv::getRotationMatrix2D(center, angle, scale);
    cv::warpAffine(image, rotated_image, rot, image.size());

    cv::imshow("Original Image", image);
    cv::imshow("Cropped Image", cropped_image);
    cv::imshow("Resized Image", resized_image);
    cv::imshow("Rotated Image", rotated_image);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}