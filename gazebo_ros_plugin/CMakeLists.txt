cmake_minimum_required(VERSION 2.8.3)
project(gazebo_ros_plugin)

# Load catkin and all dependencies required for this package
find_package(catkin REQUIRED COMPONENTS
  roscpp
  gazebo_ros
  rospy
  std_msgs
message_generation
)

 add_service_files(
   FILES
Set_position.srv
Set_activation.srv
)

 generate_messages(
   DEPENDENCIES
   std_msgs
 )

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

# Depend on system install of Gazebo
find_package(gazebo REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")

link_directories(${GAZEBO_LIBRARY_DIRS})
include_directories(${Boost_INCLUDE_DIR} ${catkin_INCLUDE_DIRS} ${GAZEBO_INCLUDE_DIRS})

catkin_package(
  CATKIN_DEPENDS
    roscpp
    gazebo_ros
  LIBRARIES ${PROJECT_NAME}
)



#add_library(${PROJECT_NAME} src/ServicePlugin.cpp)
#target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})
#add_executable(ServicePlugin src/ServicePlugin.cpp)
add_library(ServicePlugin SHARED src/ServicePlugin.cpp)
target_link_libraries(ServicePlugin ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})

#add_executable(joint_position src/joint_position.cpp)
add_library(joint_position SHARED src/joint_position.cpp)
target_link_libraries(joint_position ${GAZEBO_LIBRARIES})

#add_executable(positioner_plugin src/positioner_plugin.cpp)
add_library(positioner_plugin SHARED src/positioner_plugin.cpp)
target_link_libraries(positioner_plugin ${GAZEBO_LIBRARIES})

add_executable(Set_activation_server src/Set_activation_server.cpp)
target_link_libraries(Set_activation_server ${catkin_LIBRARIES})
add_dependencies(Set_activation_server gazebo_ros_plugin_gencpp)

add_executable(Set_activation_client src/Set_activation_client.cpp)
target_link_libraries(Set_activation_client ${catkin_LIBRARIES})
add_dependencies(Set_activation_client gazebo_ros_plugin_gencpp)


install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(DIRECTORY worlds
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
