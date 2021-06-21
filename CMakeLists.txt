cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)

project(GameplaySystem)

find_package(absl CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(Protobuf CONFIG REQUIRED)

if(WIN32)
    # Standard MSVC flags.
    add_compile_options("/std:c++17")
    add_compile_options("/D _WIN32_WINNT=0x0A00")
endif(WIN32)

add_subdirectory(Proto)
