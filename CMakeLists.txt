cmake_minimum_required(VERSION 3.29)
project(Praktikum4_V2 C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -std=c89 -Werror -pedantic -Wextra -pedantic-errors -Wconversion -Walloc-zero -Wcast-qual -Wfloat-equal")

add_executable(Praktikum4_V2 main.c
        root/root.c
        root/root.h)

target_link_libraries(Praktikum4_V2 m)