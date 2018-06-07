#include "ros/ros.h"
#include "/home/luis/catkin_ws/src/gazebo_ros_plugin/include/gazebo_ros_plugin/Set_activation.h"

bool add(gazebo_ros_plugin::Set_activation::Request  &req,
         gazebo_ros_plugin::Set_activation::Response &res)
{
  res.resu = req.activation;
  ROS_INFO("request: activation=%ld, ", (long int)req.activation);
  ROS_INFO("sending back response: [%ld]", (long int)res.resu);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "Set_activation_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("Set_activation", add);
  ROS_INFO("Ready to add two ints.");
  ros::spin();

  return 0;
}
