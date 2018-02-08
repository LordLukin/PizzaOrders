cmake_minimum_required(VERSION 2.8)

project(PizzaOrders)
add_definitions(-std=c++14)
include_directories(src)
add_executable(PizzaOrders src/main.cpp src/Pizza.cpp src/Ingredient.cpp)
