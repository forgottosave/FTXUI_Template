cmake_minimum_required(VERSION 3.27)

find_package(PkgConfig REQUIRED)

add_library(util util.cpp 
                 util.hpp)

add_library(ostui::util ALIAS util)
