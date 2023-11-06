cmake_minimum_required(VERSION 3.26)
project(medcine C)

set(CMAKE_C_STANDARD 11)

add_executable(medcine main.c
        "patient information.h"
        "patient information.c")
target_link_libraries(medcine sqlite3)
