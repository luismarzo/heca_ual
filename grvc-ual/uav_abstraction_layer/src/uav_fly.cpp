#include "ros/ros.h"
#include "uav_abstraction_layer/ual.h"
#include "stdio.h"

#include <uav_abstraction_layer/backend.h>
#include <uav_abstraction_layer/GoToWaypoint.h>
#include <uav_abstraction_layer/TakeOff.h>
#include <uav_abstraction_layer/Land.h>
#include <uav_abstraction_layer/SetVelocity.h>
#include <uav_abstraction_layer/GoToWaypointGeo.h>
#include <std_msgs/String.h>
#include <thread>

//#include "uav_abstracion_layer/takeoff.h"

int main(int _argc, char** _argv) {
    ros::init(_argc,_argv,"takeOffClient");

    //init services


    ros::NodeHandle n;
    ros::ServiceClient take_off_1 = n.serviceClient<uav_abstraction_layer::TakeOff>("uav_1/ual/take_off");  
    //ros::ServiceClient take_off_2 = n.serviceClient<uav_abstraction_layer::TakeOff>("uav_2/ual/take_off");
    //ros::ServiceClient take_off_3 = n.serviceClient<uav_abstraction_layer::TakeOff>("uav_3/ual/take_off");

    ros::ServiceClient go_to_waypoint_1 = n.serviceClient<uav_abstraction_layer::GoToWaypoint>("uav_1/ual/go_to_waypoint");
    //ros::ServiceClient go_to_waypoint_2 = n.serviceClient<uav_abstraction_layer::GoToWaypoint>("uav_2/ual/go_to_waypoint");
    //ros::ServiceClient go_to_waypoint_3 = n.serviceClient<uav_abstraction_layer::GoToWaypoint>("uav_3/ual/go_to_waypoint");



    ros::ServiceClient land_1 = n.serviceClient<uav_abstraction_layer::Land>("uav_1/ual/land");
    //ros::ServiceClient land_2 = n.serviceClient<uav_abstraction_layer::Land>("uav_2/ual/land");
    //ros::ServiceClient land_3 = n.serviceClient<uav_abstraction_layer::Land>("uav_3/ual/land");


    //ros::ServiceClient go_to_waypoint_geo_1 = n.serviceClient<uav_abstraction_layer::GoToWaypointGeo>("uav_1/ual/go_to_waypoint_geo");
    //ros::ServiceClient go_to_waypoint_geo_2 = n.serviceClient<uav_abstraction_layer::GoToWaypointGeo>("uav_2/ual/go_to_waypoint_geo");
    //ros::ServiceClient go_to_waypoint_geo_3 = n.serviceClient<uav_abstraction_layer::GoToWaypointGeo>("uav_3/ual/go_to_waypoint_geo");

    ros::ServiceClient velocity_1 = n.serviceClient<uav_abstraction_layer::SetVelocity>("uav_1/ual/velocity");
    //ros::ServiceClient velocity_2 = n.serviceClient<uav_abstraction_layer::SetVelocity>("uav_2/ual/velocity");
    //ros::ServiceClient velocity_3 = n.serviceClient<uav_abstraction_layer::SetVelocity>("uav_3/ual/velocity");



    //take off-----------------------------------
    uav_abstraction_layer::TakeOff t_off;
    t_off.request.height = 5;
    t_off.request.blocking = false;

    //waypoint-----------------------------------
    uav_abstraction_layer::GoToWaypoint way;
    way.request.waypoint.header.seq = 0;
    way.request.waypoint.pose.position.x = 3;
    way.request.waypoint.pose.position.y = 3;
    way.request.waypoint.pose.position.z = 3;
    way.request.waypoint.pose.orientation.x = 0;
    way.request.waypoint.pose.orientation.y = 0;
    way.request.waypoint.pose.orientation.z = 0;
    way.request.waypoint.pose.orientation.w = -1;
    way.request.blocking = false;

    //waypoint_geo
    // uav_abstraction_layer::GoToWaypointGeo geo;
    // geo.request.waypoint.latitude = -3;
    // geo.request.waypoint.longitude = -3;
    // geo.request.waypoint.altitude = 3;
    // geo.request.blocking = false;

    //velocity
    uav_abstraction_layer::SetVelocity vel;
    vel.request.velocity.twist.linear.x = 100;
    vel.request.velocity.twist.linear.y = 100;
    vel.request.velocity.twist.linear.z = 100;
    vel.request.velocity.twist.angular.x = 100;
    vel.request.velocity.twist.angular.y = 100;
    vel.request.velocity.twist.angular.z = 100;


    //land---------------------------------------
    uav_abstraction_layer::Land land;
    land.request.blocking= false;
    std::cout << "Vamos a llamar al servicio" << std::endl;

    take_off_1.call(t_off);
    //take_off_2.call(t_off);
    //take_off_3.call(t_off);


    sleep(10);
    velocity_1.call(vel);
    //velocity_2.call(vel);
    //velocity_3.call(vel);


    sleep(10);
    go_to_waypoint_1.call(way);
    //go_to_waypoint_2.call(way);
    //go_to_waypoint_3.call(way);

    //geo
    //go_to_waypoint_geo_1.call(geo);
    //go_to_waypoint_geo_2.call(geo);
    //go_to_waypoint_geo_3.call(geo);
    std::cout << "Mandadoo" << std::endl;

    sleep(9);
    std::cout << "Aterrizando" << std::endl;
    land_1.call(land);
   // land_2.call(land);
    //land_3.call(land);
    
    int salir;
    while( 1 )
    {
       
        std::cin >> salir;
        break;
    }

    return 0;
}

