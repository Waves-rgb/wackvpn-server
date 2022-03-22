cmake_minimum_required(VERSION 3.21)
project(WackVPNServer)
set(CMAKE_CXX_STANDARD 20)

include_directories(dep/fmt/include)

file(GLOB_RECURSE SRC_FILES src/*)
add_executable(WackVPNServer ${SRC_FILES} ${DEP_SRC})