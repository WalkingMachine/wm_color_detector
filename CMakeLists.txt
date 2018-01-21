cmake_minimum_required(VERSION 3.5)
set (CMAKE_AUTOMOC ON)
set (CMAKE_INCLUDE_CURRENT_DIR ON)
project(wm_color_detector)

set(THREADS_PREFER_PTHREAD_FLAG ON)

## Find catkin macros and libraries
find_package(Threads REQUIRED)
find_package(catkin REQUIRED COMPONENTS
        roscpp
        sensor_msgs
        cv_bridge)
find_package(message_generation REQUIRED CATKIN_DEPENDS message_runtime)

## Find OpenCV libraries
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

add_message_files(
        FILES
        Coloration.msg
        BoundingBox.msg
)

add_service_files(
        FILES
        AnalyseColor.srv
)

generate_messages(
        DEPENDENCIES
        std_msgs
        sensor_msgs
)

set(CMAKE_CXX_STANDARD 11)

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(${catkin_INCLUDE_DIRS})

add_executable(test_node
        src/ColorationAnalyser.cpp
        src/Color_Analyzer.cpp
)

add_executable(test_node_read
        src/test2.cpp
        src/Color_Analyzer.cpp
)

target_link_libraries(test_node
        ${catkin_LIBRARIES}
        ${OpenCV_LIBRARIES}
)

target_link_libraries(test_node_read
        ${catkin_LIBRARIES}
        ${OpenCV_LIBRARIES}
)
