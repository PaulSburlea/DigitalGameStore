cmake_minimum_required(VERSION 3.30)
project(GameStore)

set(CMAKE_CXX_STANDARD 17)

add_executable(GameStore src/main.cpp
        include/Game.h
        include/Bundle.h
        include/Cli.h
        include/Store.h
        include/User.h
        src/Bundle.cpp
        src/Cli.cpp
        src/Game.cpp
        src/Store.cpp
        src/User.cpp)
