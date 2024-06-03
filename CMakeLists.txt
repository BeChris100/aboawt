cmake_minimum_required(VERSION 3.10)
project(aboawt)

if (NOT CMAKE_SYSTEM_NAME STREQUAL "Linux" AND NOT CMAKE_SYSTEM_NAME STREQUAL "Android")
    message(FATAL_ERROR "This project is meant to be built on Android (Termux) / Linux, not on Windows or macOS!")
endif ()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++ -fPIC")

include_directories("include")

add_library(aboawt-global STATIC
        src/Application/Definitions.cpp
        src/Application/Utils.cpp
        src/Swap/SwapManager.cpp
        src/Application/Core.cpp
        src/Android/BatteryManager.cpp
        src/Android/Classpaths.cpp
        src/CmdLine.cpp
        src/Application/PkgMgr.cpp)

add_executable(aboawt src/main.cpp)

target_link_libraries(aboawt PRIVATE aboawt-global)

if (EXISTS "${CMAKE_SOURCE_DIR}/src/TestMain.cpp")
    message("Creating testing executable")

    add_executable(aboawt-test src/TestMain.cpp)

    target_link_libraries(aboawt-test PRIVATE aboawt-global)
endif ()