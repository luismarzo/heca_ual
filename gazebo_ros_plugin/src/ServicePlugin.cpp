#include <gazebo/common/Plugin.hh>
#include <ros/ros.h>
#include "/home/luis/catkin_ws/src/gazebo_ros_plugin/include/service_tutorial/Set_position.h"
#include "service_tutorial/Set_position.h"
#include "stdio.h"
#include <fstream>

namespace gazebo
{
class ServicePlugin : public WorldPlugin
{
public:
  ServicePlugin() : WorldPlugin()
  {
  }

  bool Model_pose(service_tutorial::Set_position::Request &req,
                         service_tutorial::Set_position::Response &res)
  {
    res.resu1 = req.x;
    res.resu2 = req.y;
    res.resu3 = req.z;
    res.resu4 = req.roll;
    res.resu5 = req.pitch;
    res.resu6 = req.yaw;
    //ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
    ROS_INFO("sending back response: [%ld,%ld,%ld,%ld,%ld,%ld]", (long int)res.resu1,
             (long int)res.resu2,
             (long int)res.resu3,
             (long int)res.resu4,
             (long int)res.resu5,
             (long int)res.resu6);
    return true;
  }

  bool Model_autopose(service_tutorial::Set_position::Request &req,
                         service_tutorial::Set_position::Response &res)
  {

    res.resu1 = 10;
    res.resu2 = 20;
    res.resu3 = 30;
    res.resu4 = 40;
    res.resu5 = 50;
    res.resu6 = 60;
    ROS_INFO("sending auto back response: [%ld,%ld,%ld,%ld,%ld,%ld]", (long int)res.resu1,
             (long int)res.resu2,
             (long int)res.resu3,
             (long int)res.resu4,
             (long int)res.resu5,
             (long int)res.resu6);
    return true;



  }

  void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
  {
    // Make sure the ROS node for Gazebo has already been initialized
    if (!ros::isInitialized())
    {
      ROS_FATAL_STREAM("A ROS node for Gazebo has not been initialized, unable to load plugin. "
                       << "Load the Gazebo system plugin 'libgazebo_ros_api_plugin.so' in the gazebo_ros package)");
      return;
    }

    ROS_INFO("\n\nPluging activated!\n");
    ros::NodeHandle n;
    service = n.advertiseService("Set_position", &ServicePlugin::Model_pose, this);
    autoservice = n.advertiseService("Set_autoposition", &ServicePlugin::Model_autopose, this);
    ROS_INFO("Ready.");
	

    archivo.open("Debugador_ServicePlugin.txt");
    archivo <<  "\n" <<"Crea el archivo correctamente en la carpeta /tmp/px4_sitl_files/"  << std::endl;
    //luis();
  }

  bool luis()
  {
    ROS_INFO("luis entra");
    return 0;
  }

private:

  ros::ServiceServer service;
  ros::ServiceServer autoservice;
  std::ofstream archivo;
};
GZ_REGISTER_WORLD_PLUGIN(ServicePlugin)
}
