cmake_minimum_required(VERSION 3.10)
project(PostureGuard)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

find_package(OpenCV REQUIRED COMPONENTS dnn)


add_executable(PostureGuard
    src/main.cpp
    src/FaceDetector.cpp
    src/DistanceCalculator.cpp
    src/AlertSystem.cpp
)

target_include_directories(PostureGuard
    PRIVATE include
    PRIVATE ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(PostureGuard
    ${OpenCV_LIBS}
)