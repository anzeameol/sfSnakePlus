cmake_minimum_required(VERSION 3.15)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

project(snake)

add_executable(snake main.cpp Fruit.cpp Game.cpp GameOverScreen.cpp GameScreen.cpp MenuScreen.cpp Screen.cpp Snake.cpp SnakeNode.cpp Math.cpp Grid.cpp OptionScreen.cpp)

target_include_directories(snake PRIVATE ${CMAKE_SOURCE_DIR}/tools/include)
target_link_directories(snake PRIVATE ${CMAKE_SOURCE_DIR}/tools/lib)
target_link_libraries(snake PRIVATE sfml-audio sfml-graphics sfml-network sfml-system sfml-window)

target_compile_options(snake PRIVATE -std=c++17)