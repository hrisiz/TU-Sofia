project("MyCVAlgorithm")
cmake_minimum_required(VERSION 3.15)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} opencv_core opencv_highgui opencv_imgcodecs opencv_imgproc)