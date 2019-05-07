cmake_minimum_required(VERSION 3.13)
project(GraphCPro)

set(CMAKE_CXX_STANDARD 14)

add_executable(GraphCPro main.cpp Graph.cpp Graph.h Tourism.cpp Tourism.h stdafx.h menu.cpp menu.h)