cmake_minimum_required(VERSION 3.10)

project(FirstCCliParser VERSION 1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(FirstCCliParser ./src/main.c ./src/parser.c)
