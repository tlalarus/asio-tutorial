cmake_minimum_required(VERSION 3.23)
project(asio_tutorial)

set(CMAKE_CXX_STANDARD 11)

find_package(Threads REQUIRED)
find_package(Boost COMPONENTS filesystem system serialization REQUIRED)

add_subdirectory(timer1)
add_subdirectory(timer2)


