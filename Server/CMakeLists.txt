cmake_minimum_required(VERSION 3.20)
project(Server)

set(CMAKE_CXX_STANDARD 23)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(server SocketServer.cpp SocketServer.h Breakout.cpp Brick.cpp Brick.h Painter.cpp Painter.h Wall.cpp Wall.h Force.cpp Force.h Ball.cpp Ball.h Game.cpp Game.h Pedal.cpp Pedal.h)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(server ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )