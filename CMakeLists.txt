cmake_minimum_required(VERSION 3.2...3.27.5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(cmake_prj)

enable_testing()
add_subdirectory(lib/googletest)


add_subdirectory(obychaika)
add_subdirectory(sort)
add_subdirectory(unit_test)
add_subdirectory(BigInt)
add_subdirectory(d_linkly)
add_subdirectory(vector)



set(CMAKE_SUPPRESS_REGENERATION true)
