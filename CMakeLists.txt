cmake_minimum_required(VERSION 3.7)
project(tetravex VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-pthread)

link_libraries(pthread)

add_executable(tetravex main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
