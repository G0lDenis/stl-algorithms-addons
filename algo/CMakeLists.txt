# Declare the library target
add_library(py_algo INTERFACE)
target_sources(py_algo INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/py_algo.h)

# Set the include directory
target_include_directories(py_algo INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Install the headers
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
        DESTINATION include
        FILES_MATCHING PATTERN "*.h")
