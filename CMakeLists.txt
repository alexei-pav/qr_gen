cmake_minimum_required(VERSION 3.10)
project(qr-gen)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(qr-gen src/main.cpp src/qr_code.cpp)

# We need to find SFML
find_package(SFML 2.6 COMPONENTS graphics window REQUIRED)

# Link libraries
target_link_libraries(qr-gen PRIVATE sfml-graphics sfml-window)

# Add include directories
target_include_directories(qr-gen PRIVATE include/)
