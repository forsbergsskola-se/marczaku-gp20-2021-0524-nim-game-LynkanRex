cmake_minimum_required(VERSION 3.19)
project(nimgame)

set(CMAKE_CXX_STANDARD 14)

add_executable(program
        program.cpp program.h nim.cpp binaryconverter.cpp binaryconverter.h program.cpp program.h nim.h tictactoe.cpp tictactoe.h)
