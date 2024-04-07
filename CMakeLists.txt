cmake_minimum_required(VERSION 3.10)

project(mini-mario)

add_executable(mini-mario
        src/App.h
        src/main.cpp
        src/renderer/Renderer.cpp
        src/renderer/Renderer.h
)

target_include_directories(mini-mario PUBLIC "{$CMAKE_SOURCE_DIR}/src")