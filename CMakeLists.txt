cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SDL2Test)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

cmake_policy(SET CMP0077 NEW)
option(WIN_Build "build for windows" OFF)
if(WIN_Build)
    set(SDL2_DIR "thirdParty/sdl_win")
endif()

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

add_executable(SnakeGame src/main.cpp src/game.cpp src/controller.cpp src/renderer.cpp src/snake.cpp)

string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)

target_link_libraries(SnakeGame ${SDL2_LIBRARIES})

if(WIN_Build)
    add_custom_command(TARGET SnakeGame POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${PROJECT_SOURCE_DIR}/thirdParty/sdl_win/lib/x64/SDL2.dll"
            $<TARGET_FILE_DIR:SnakeGame>)
endif()