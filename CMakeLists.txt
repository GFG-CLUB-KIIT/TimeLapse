cmake_minimum_required(VERSION 3.12)
project(elapso VERSION 0.1.0)

#execuatable name
set(EXECUTABLE_NAME "elapso")

find_package(OpenCV REQUIRED)
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

add_executable(${EXECUTABLE_NAME} src/main.cpp)
target_link_libraries( ${EXECUTABLE_NAME} ${OpenCV_LIBS} )
target_link_libraries(${EXECUTABLE_NAME} stdc++fs)