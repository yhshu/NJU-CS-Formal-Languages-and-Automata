cmake_minimum_required(VERSION 3.10)  # CMake version check
project(turing_machine)
set(CMAKE_CXX_STANDARD 14)

add_executable(turing_machine turing-project/main.cpp turing-project/TuringMachine.h turing-project/TuringMachine.cpp turing-project/TransitionFunction.cpp turing-project/TransitionFunction.h turing-project/utils.h turing-project/utils.cpp)