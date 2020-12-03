cmake_minimum_required(VERSION 3.10)  # CMake version check
project(nju_cs_fla_fall_2020_project)
set(CMAKE_CXX_STANDARD 14)

add_executable(turing turing-project/main.cpp turing-project/TuringMachine.h turing-project/TuringMachine.cpp turing-project/TransitionFunction.cpp turing-project/TransitionFunction.h turing-project/utils.h turing-project/utils.cpp turing-project/message.cpp turing-project/message.h)