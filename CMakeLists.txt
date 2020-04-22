#cmake_minimum_required(VERSION 3.7)
cmake_minimum_required(VERSION 3.11.3)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17 -pthread")

project(SDL2Test)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

cmake_policy(SET CMP0077 NEW)
option(WIN_Build "build for windows" OFF)
if(WIN_Build)
    set(SDL2_DIR "thirdParty/sdl_win")
endif()

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

# Find all executables
file(GLOB project_SRCS src/*.cpp) #src/*.h

# Add project executable
add_executable(SpaceEvader ${project_SRCS})

string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)

target_link_libraries(SpaceEvader ${SDL2_LIBRARIES})

if(WIN_Build)
    add_custom_command(TARGET SpaceEvader POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${PROJECT_SOURCE_DIR}/thirdParty/sdl_win/lib/x64/SDL2.dll"
            $<TARGET_FILE_DIR:SpaceEvader>)
endif()