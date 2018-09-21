cmake_minimum_required(VERSION 3.5)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
project(wm_color_detector)

set(THREADS_PREFER_PTHREAD_FLAG ON)

## Find catkin macros and libraries
find_package(Threads REQUIRED)
find_package(catkin REQUIRED
        roscpp
        sensor_msgs
        cv_bridge
        message_generation
        sara_msgs
        )
find_package(message_generation REQUIRED CATKIN_DEPENDS message_runtime)

## Find OpenCV libraries
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

add_message_files(
        FILES
        Coloration.msg
)

add_service_files(
        FILES
        AnalyseColor.srv
)

generate_messages(
        DEPENDENCIES
        sensor_msgs
        sara_msgs
)

catkin_package(
        LIBRARIES ColorationAnalyser
        CATKIN_DEPENDS roscpp message_runtime sara_msgs sara_msgs
)


set(CMAKE_CXX_STANDARD 11)

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
        src
        ${catkin_INCLUDE_DIRS}
)

add_executable(ColorationAnalyser
        src/ColorationAnalyser.cpp
        src/Color_Analyzer.cpp
        )
# Specify libraries to link a library or executable target against
target_link_libraries(ColorationAnalyser
        ${catkin_LIBRARIES}
        ${OpenCV_LIBRARIES}
        )

add_dependencies(ColorationAnalyser ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
