#include "boost/bind.hpp"
#include "gazebo/gazebo.hh"
#include "gazebo/physics/physics.hh"
#include "gazebo/common/common.hh"
#include "stdio.h"
#include <fstream>

#include "gazebo/physics/PhysicsIface.hh"
#include "gazebo/physics/Model.hh"
#include "gazebo/physics/World.hh"
#include "gazebo/physics/ContactManager.hh"
#include "gazebo/physics/PhysicsEngine.hh"
#include "gazebo/physics/Collision.hh"
#include "gazebo/physics/Link.hh"
#include <gazebo/physics/Inertial.hh>

#include <gazebo/common/Plugin.hh>
#include <ros/ros.h>
#include "/home/luis/catkin_ws/src/gazebo_ros_plugin/include/service_tutorial/Set_position.h"
#include "service_tutorial/Set_position.h"
//#include "service_tutorial/Set_position.h"
//#include <LinkConfig.hh>
// In the real file these quotes are greater-than and less-than but I
// don't know how to get that to show up in my question

namespace gazebo
{
  class joint_position : public ModelPlugin
  {
  public: void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
    {	



        this->model = _parent;
	this->world= this->model->GetWorld();
 	this->mbox=this->world->GetModel("minibox");
	//gazebo::math::Pose diff = mbox->GetLink()->GetWorldPose() - this->model->GetWorldPose();
	this->jointR1_ = this->model->GetJoint("r1");
	this->link1 = this->mbox->GetLink("link");

	this->link1->GetInertial()->SetMass(80); // Cambia la masa a 800000
	this ->link1 ->UpdateMass();
	//this->link1->UpdateParameters(sdflink);
	//archivo.open("Debugador_joint_c.txt");
	//archivo << model->GetName()<< "\n" <<mbox->GetName()  << std::endl;
	std::cout<<" \ntimee \n"<<std::endl;	

	//Server
	 if (!ros::isInitialized())
	    {
	      ROS_FATAL_STREAM("A ROS node for Gazebo has not been initialized, unable to load plugin. "
		               << "Load the Gazebo system plugin 'libgazebo_ros_api_plugin.so' in the gazebo_ros package)");
	      return;
	    }

	    ROS_INFO("\n\nPluging activated!\n");
	    ros::NodeHandle n;
	    service = n.advertiseService("Set_position", &joint_position::Model_pose, this);
	    autoservice = n.advertiseService("Set_autoposition", &joint_position::Model_autopose, this);
	    ROS_INFO("Ready.");




    this->updateConnection = event::Events::ConnectWorldUpdateBegin(boost::bind(&joint_position::OnUpdate, this, _1));
    }

  
  public: void OnUpdate(const common::UpdateInfo &_info)
    {
	

		//Ninguno estático
		if(_info.simTime.Float()>2 && _info.simTime.Float()<10){
		 this->mbox->SetStatic(false);
		this->model->SetStatic(false);	
		

		 //this -> mbox->Update	
		 this->model->AttachStaticModel(this->mbox,math::Pose(0,0,0.6,0,0,0));
		 link1->AttachStaticModel(this->mbox,math::Pose(0,0,0.6,0,0,0));
		 	if(_info.simTime.Float()>5){
     		this->jointR1_->SetVelocity(0, 0.5);
		 	}
		 }

		//Caja pequeña estática

		if(_info.simTime.Float()>15 && _info.simTime.Float()<25){
		
		this->model->SetStatic(false);		
		this->model->AttachStaticModel(this->mbox,math::Pose(0,0,0.6,0,0,0));
		link1->AttachStaticModel(this->mbox,math::Pose(0,0,0.6,0,0,0));
			if(_info.simTime.Float()>20){
     			this->jointR1_->SetVelocity(0, 0.5);
			}
		}
		//Caja grande estática
		if(_info.simTime.Float()>25 && _info.simTime.Float()<35){
		this->mbox->SetStatic(false);
		this->model->SetStatic(true);		
		this->model->AttachStaticModel(this->mbox,math::Pose(0,0,0.6,0,0,0));
		link1->AttachStaticModel(this->mbox,math::Pose(0,0,0.6,0,0,0));
			if(_info.simTime.Float()>30){
     			this->jointR1_->SetVelocity(0, 0.5);
			}
		}
		//Ambos estáticos
		if(_info.simTime.Float()>35 && _info.simTime.Float()<45){
		this->mbox->SetStatic(true);
		this->model->SetStatic(true);		
		this->model->AttachStaticModel(this->mbox,math::Pose(0,0,0.6,0,0,0));
		link1->AttachStaticModel(this->mbox,math::Pose(0,0,0.6,0,0,0));
			if(_info.simTime.Float()>40){
     			this->jointR1_->SetVelocity(0, 0.5);
			}
		}

		math::Pose staticPose(posx,posy,posz,roll,pitch,yaw);
		this->mbox->SetWorldPose(staticPose);

    }


 bool Model_pose(service_tutorial::Set_position::Request &req,
                         service_tutorial::Set_position::Response &res)
  {
    posx = res.resu1 = req.x;
    posy = res.resu2 = req.y;
    posz = res.resu3 = req.z;
    roll = res.resu4 = req.roll;
    pitch = res.resu5 = req.pitch;
    yaw = res.resu6 = req.yaw;
    //ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
    ROS_INFO("sending back response: [%ld,%ld,%ld,%ld,%ld,%ld]", (long int)res.resu1,
             (long int)res.resu2,
             (long int)res.resu3,
             (long int)res.resu4,
             (long int)res.resu5,
             (long int)res.resu6);
math::Pose staticPose(res.resu1,res.resu2,res.resu3,res.resu4,res.resu5,res.resu6);
this->mbox->SetWorldPose(staticPose);
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

    
    common::Time last_update_time_;

  private: 

	   physics::ModelPtr model;
	   physics::ModelPtr mbox;
	   physics::WorldPtr world;
  	   event::ConnectionPtr updateConnection;
  	   std::ofstream archivo;
   	   physics::JointPtr jointR1_;
	   physics::LinkPtr  link1;
	   int cnt=0;
	   physics::InertialPtr mass;
	   physics::LinkPtr linkb;
	   physics::JointPtr jointt;
	   sdf::ElementPtr sdflink;
	   ignition::math::Pose3d Pos;
		math::Vector3 axis_ex;
		math::Angle high_stop_ex;
		boost::any cfm_ex;
		physics::LinkPtr clink;
	  ros::ServiceServer service;
	  ros::ServiceServer autoservice;
	  long int posx=1, posy=1, posz=1, roll=1, pitch=1 ,yaw=1;
	 	

  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(joint_position)
}
