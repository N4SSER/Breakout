cmake_minimum_required(VERSION 3.20)
project(Server)

set(CMAKE_CXX_STANDARD 23)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(server main.cpp SocketServer.cpp SocketServer.h)
