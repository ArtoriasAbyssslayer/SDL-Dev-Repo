cmake_minimum_required(VERSION 3.10)

project(SnakeGame)

# Add the path to the SDL2 headers
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

# Support both 32 and 64 bit builds
if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
    set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2main.lib")
else ()
    set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2main.lib")
endif ()

string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)

# Add your source files
add_executable(SnakeGame src/MainSnakegame.cpp)

# Link SDL2 libraries
target_link_libraries(SnakeGame ${SDL2_LIBRARIES})
