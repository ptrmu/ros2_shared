cmake_minimum_required(VERSION 3.12)
project(ros2_shared)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find packages
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# Create a modern CMake target
add_library(ros2_shared INTERFACE)
add_library(ros2_shared::ros2_shared ALIAS ros2_shared)

# ros2_shared depends on rclcpp
target_link_libraries(ros2_shared
  INTERFACE
    rclcpp::rclcpp)

# Install
install(TARGETS ros2_shared
  EXPORT ros2_shared_targets
  INCLUDES DESTINATION include)

install(DIRECTORY include/
  DESTINATION include)

# Export
ament_export_targets(ros2_shared_targets)
ament_export_dependencies(rclcpp)

ament_package()
