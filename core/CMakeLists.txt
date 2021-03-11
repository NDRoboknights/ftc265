cmake_minimum_required(VERSION 3.9)

project(ftc265 VERSION 2020.1.0)

# Find librealsense2
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src/main/cpp/include")

# We only support C++17 and above
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
