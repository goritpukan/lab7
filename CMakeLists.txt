cmake_minimum_required(VERSION 3.30)
project(lab7 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab7 main.c
        include/io.h
        src/io.c
        include/colors.h
        include/calculations.h
        src/calculations.c)
target_link_libraries(lab7 m)
