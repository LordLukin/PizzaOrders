cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(PizzaOrders)
aux_source_directory(src SRC_LIST)
include_directories(src)
add_executable(PizzaOrders ${SRC_LIST})