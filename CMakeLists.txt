cmake_minimum_required(VERSION 2.8)

project(PizzaOrders)
#add_definitions(-std=c++14)
aux_source_directory(src SRC_LIST)
include_directories(src)
add_executable(PizzaOrders ${SRC_LIST})