cmake_minimum_required(VERSION 3.8)
project(kratos_rishitkhanna)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)


find_package(rclcpp REQUIRED)

find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(builtin_interfaces REQUIRED)


rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Roverquestionthree.msg"
  DEPENDENCIES geometry_msgs builtin_interfaces# Add packages that above messages depend on, in this case geometry_msgs for Sphere.msg
)
add_executable(talker src/q1_publisher_lambda_function.cpp)
target_link_libraries(talker PUBLIC rclcpp::rclcpp ${std_msgs_TARGETS})
add_executable(listener src/q1_subscriber_lambda_function.cpp)
target_link_libraries(listener PUBLIC rclcpp::rclcpp ${std_msgs_TARGETS})

add_executable(S_one src/q2_first_publisher.cpp)
target_link_libraries(S_one PUBLIC rclcpp::rclcpp ${std_msgs_TARGETS})
add_executable(S_two src/q2_second_publisher.cpp)
target_link_libraries(S_two PUBLIC rclcpp::rclcpp ${std_msgs_TARGETS})

add_executable(second src/q4_seconds.cpp)
target_link_libraries(second PUBLIC rclcpp::rclcpp ${std_msgs_TARGETS})
add_executable(minute src/q4_minutes.cpp)
target_link_libraries(minute PUBLIC rclcpp::rclcpp ${std_msgs_TARGETS})
add_executable(hour src/q4_hours.cpp)
target_link_libraries(hour PUBLIC rclcpp::rclcpp ${std_msgs_TARGETS})
add_executable(clock src/q4_clock.cpp)
target_link_libraries(clock PUBLIC rclcpp::rclcpp ${std_msgs_TARGETS})

install(TARGETS
  talker
  listener
  S_one
  S_two
  second
  minute
  hour
  clock
  DESTINATION lib/${PROJECT_NAME})
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
