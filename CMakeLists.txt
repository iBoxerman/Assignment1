cmake_minimum_required(VERSION 3.17)
project(Assignment1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Assignment1 src/main.cpp src/Graph.cpp src/Agent.cpp src/Session.cpp src/Tree.cpp
        include/Graph.h include/Agent.h include/Session.h include/Tree.h test.json)