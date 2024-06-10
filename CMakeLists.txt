cmake_minimum_required(VERSION 3.10)
# set the projectX name to the name of your project
project(game_of_life)

set(CMAKE_CXX_STANDARD 17)
# set(SOURCE_FILES main.cpp)

add_executable(game_of_life main.cpp
        GameOfLife.h
        GameOfLife.cpp
        Tile.h
        Tile.cpp)
#add_executable(Game ${SOURCE_FILES})


# Detect and add SFML
find_package(SFML 2.6.1 REQUIRED system window graphics network audio)
include_directories(D:\\AGH\\ISI_semestr2\\PP2\\game_of_life\\SFML-2.6.1\\include\\SFML)
target_link_libraries(game_of_life sfml-graphics sfml-window sfml-system)
