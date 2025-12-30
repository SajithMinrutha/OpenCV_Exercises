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
        return 1;
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

    cv::Mat blurred_image;
    cv::GaussianBlur(image, blurred_image, cv::Size(5, 5), 0);
    cv::imshow("Blurred Image (Gaussian)", blurred_image);

    cv::Mat sharpened_image;
    cv::Mat kernel = (cv::Mat_<float>(3, 3) << 0, -1, 0,
                      -1, 5, -1,
                      0, -1, 0);

    cv::filter2D(image, sharpened_image, -1, kernel);
    cv::imshow("Sharpened Image", sharpened_image);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}