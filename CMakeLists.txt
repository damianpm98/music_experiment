cmake_minimum_required(VERSION 3.18.1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(music_experiment VERSION 0.1.0)

add_executable(${PROJECT_NAME} src/main.cpp src/Musician.cpp src/Metronome.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
