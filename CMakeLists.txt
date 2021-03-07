cmake_minimum_required(VERSION 3.10)

project(chtheme VERSION 1.0)
set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(chtheme src/chtheme.cpp src/functions.cpp src/functions.hpp)
target_compile_features(chtheme PRIVATE cxx_std_17)
