CMAKE_MINIMUM_REQUIRED(VERSION 3.12)
project(py_algorithms)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE RELEASE)

add_subdirectory(algo)
set(ENABLE_TESTING ON)

if (ENABLE_TESTING)
    add_subdirectory(tests)
    enable_testing()
endif(ENABLE_TESTING)
