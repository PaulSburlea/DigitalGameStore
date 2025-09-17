cmake_minimum_required(VERSION 3.30)
project(GameStore)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(GameStore src/main.cpp
        include/Game.h
        include/Bundle.h
        include/Store.h
        include/User.h
        src/Bundle.cpp
        src/Game.cpp
        src/Store.cpp
        src/User.cpp
        include/AdminCli.h
        src/AdminCli.cpp
        include/UserCli.h
        src/UserCli.cpp)
