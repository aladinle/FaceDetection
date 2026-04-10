cmake_minimum_required(VERSION 3.15)
project(FaceDetection)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED CONFIG)

add_executable(face_detection src/main.cpp)
target_link_libraries(face_detection PRIVATE ${OpenCV_LIBS})

file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/images DESTINATION ${CMAKE_BINARY_DIR})