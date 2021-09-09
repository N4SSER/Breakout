cmake_minimum_required(VERSION 3.20)
project(Client)

set(CMAKE_CXX_STANDARD 23)
SET(CMAKE_CXX_FLAGS -pthread)
add_executable(Client main.cpp SocketClient.cpp SocketClient.h)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(Client ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )