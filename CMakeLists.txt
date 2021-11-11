cmake_minimum_required(VERSION 3.0)

project(detect)

## dependencies

include_directories(/usr/include/eigen3)

include_directories(include)

## Find packages

find_package(OpenCV COMPONENTS core imgproc highgui calib3d REQUIRED)

## detectlib

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(visiona SHARED src/Visiona.cpp src/DebugPlotConfig.cpp src/MarkerDetector_impl.cpp src/MarkerDetectorConfig.cpp src/Timer.cpp)

target_link_libraries(visiona config++ opencv_core opencv_calib3d opencv_highgui opencv_imgproc)

## batchdetector

add_executable(batchdetector src/batchdetector.cpp)

target_link_libraries(batchdetector visiona)

## install

install(TARGETS visiona DESTINATION lib)

install(FILES include/Visiona.h DESTINATION include)
install(FILES include/DebugPlotConfig.h DESTINATION include)
install(FILES include/MarkerDetectorConfig.h DESTINATION include)