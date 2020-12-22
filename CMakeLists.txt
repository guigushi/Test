project(test_1)
cmake_minimum_required(VERSION 2.6)
file(GLOB SRCS *.c *.cpp *.cc *.h *.hpp)
include_directories(include)
link_directories("/mnt/f/github/Test/lib")
link_libraries(benchmark)
link_libraries(pthread)
add_executable(${PROJECT_NAME} ${SRCS})

