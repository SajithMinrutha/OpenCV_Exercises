#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

int main()
{
    cv::VideoCapture cap(0);

    if (!cap.isOpened())
    {
        std::cerr << "Error ! couldn't open camera!" << std::endl;
        return 1;
    }

    cv::namedWindow("Live Video", cv::WINDOW_AUTOSIZE);

    while (true)
    {
        cv::Mat frame;
        cap >> frame;

        if (frame.empty())
        {
            std::cerr << "Error frame is empty" << std::endl;
            break;
        }

        cv::imshow("Live Video", frame);
        if (cv::waitKey(1) == 'q')
        {
            break;
        }
    }
    cap.release();
    cv::destroyAllWindows();
    return 0;
}