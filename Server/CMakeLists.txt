cmake_minimum_required(VERSION 3.20)
project(Server)

set(CMAKE_CXX_STANDARD 23)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(server Game/SocketServer.cpp Game/SocketServer.h Breakout.cpp Game/Brick.cpp Game/Brick.h Game/Painter.cpp Game/Painter.h Game/Wall.cpp Game/Wall.h Game/Force.cpp Game/Force.h Game/Ball.cpp Game/Ball.h Game/Game.cpp Game/Game.h Game/Paddle.cpp Game/Paddle.h)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(server ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )