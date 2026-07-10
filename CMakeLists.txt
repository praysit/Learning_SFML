cmake_minimum_required(VERSION 3.20)
project(particle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.1.0
)

# This pulls in the library
FetchContent_MakeAvailable(SFML)

add_executable(particle main.cpp)

# Link the libraries. The 'sfml-graphics' target is created by FetchContent
target_link_libraries(particle PRIVATE sfml-graphics sfml-window sfml-system)