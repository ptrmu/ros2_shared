cmake_minimum_required(VERSION 3.5)
project(ros2_shared)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()
#
# Find packages
find_package(ament_cmake REQUIRED)

# Local includes
include_directories(include)

ament_export_include_directories(include)

install(DIRECTORY include/
  DESTINATION include)

ament_package()

