cmake_minimum_required(VERSION 3.10)

project(1)

find_package(OpenCV REQUIRED)

add_executable(hello_opencv hello_opencv.cpp)
target_link_libraries(hello_opencv ${OpenCV_LIBS})

add_executable(video_read video_read.cpp)
target_link_libraries(video_read ${OpenCV_LIBS})

add_executable(editing_image editing_image.cpp)
target_link_libraries(editing_image ${OpenCV_LIBS})

add_executable(drawing drawing.cpp)
target_link_libraries(drawing ${OpenCV_LIBS})