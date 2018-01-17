cmake_minimum_required(VERSION 3.5)
set (CMAKE_AUTOMOC ON)
set (CMAKE_INCLUDE_CURRENT_DIR ON)
project(wm_color_detector)

set(THREADS_PREFER_PTHREAD_FLAG ON)

## Find catkin macros and libraries
find_package(Threads REQUIRED)
find_package(catkin REQUIRED COMPONENTS roscpp)
find_package(message_generation REQUIRED CATKIN_DEPENDS message_runtime)

## Find OpenCV libraries
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

generate_messages( DEPENDENCIES std_msgs )

set(CMAKE_CXX_STANDARD 11)

catkin_package()

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(${catkin_INCLUDE_DIRS})

add_executable(test_node
        src/test.cpp
        src/Color_Analyzer.cpp)

target_link_libraries(test_node
        ${catkin_LIBRARIES}
        ${OpenCV_LIBRARIES}
)