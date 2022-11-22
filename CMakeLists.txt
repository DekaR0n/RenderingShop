cmake_minimum_required(VERSION 3.23)
project(RenderingShop C)

set(CMAKE_C_STANDARD 23)

add_executable(RenderingShop project/main.c library/shop.h library/shop.c)
