cmake_minimum_required(VERSION 3.10)
project(aboawt)

if (NOT CMAKE_SYSTEM_NAME STREQUAL "Linux" AND NOT CMAKE_SYSTEM_NAME STREQUAL "Android")
    message(FATAL_ERROR "This project is meant to be built on Android (Termux) / Linux, not on Windows or macOS!")
endif ()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++ -fPIC")

include_directories("include")

add_executable(aboawt
        src/main.cpp
        src/Application/Definitions.cpp
        src/Application/Utils.cpp)
