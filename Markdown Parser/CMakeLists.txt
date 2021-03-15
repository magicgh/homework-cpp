cmake_minimum_required(VERSION 3.16)
project(markdown_parser)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src DIR_SRCS)

add_executable(markdown_parser ${DIR_SRCS})