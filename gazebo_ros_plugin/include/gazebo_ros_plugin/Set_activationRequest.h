#ifndef GAZEBO_ROS_PLUGIN_MESSAGE_SET_ACTIVATIONREQUEST_H
#define GAZEBO_ROS_PLUGIN_MESSAGE_SET_ACTIVATIONREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace gazebo_ros_plugin
{
template <class ContainerAllocator>
struct Set_activationRequest_
{
  typedef Set_activationRequest_<ContainerAllocator> Type;

  Set_activationRequest_()
    : activation(0)
      {
    }
  Set_activationRequest_(const ContainerAllocator& _alloc)
    : activation(0)
      {
    }



   typedef int64_t _activation_type;
  _activation_type activation;

 




  typedef boost::shared_ptr< ::gazebo_ros_plugin::Set_activationRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::gazebo_ros_plugin::Set_activationRequest_<ContainerAllocator> const> ConstPtr;

}; // struct Set_activationRequest_

typedef ::gazebo_ros_plugin::Set_activationRequest_<std::allocator<void> > Set_activationRequest;

typedef boost::shared_ptr< ::gazebo_ros_plugin::Set_activationRequest > Set_activationRequestPtr;
typedef boost::shared_ptr< ::gazebo_ros_plugin::Set_activationRequest const> Set_activationRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::gazebo_ros_plugin::Set_activationRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::gazebo_ros_plugin::Set_activationRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace gazebo_ros_plugin

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'gazebo_ros_plugin': ['/home/kunal15595/ros/ros_ws/src/gazebo_ros_plugin/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::gazebo_ros_plugin::Set_activationRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::gazebo_ros_plugin::Set_activationRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gazebo_ros_plugin::Set_activationRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gazebo_ros_plugin::Set_activationRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gazebo_ros_plugin::Set_activationRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gazebo_ros_plugin::Set_activationRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::gazebo_ros_plugin::Set_activationRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "36d09b846be0b371c5f190354dd3153e";
  }

  static const char* value(const ::gazebo_ros_plugin::Set_activationRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x36d09b846be0b371ULL;
  static const uint64_t static_value2 = 0xc5f190354dd3153eULL;
};

template<class ContainerAllocator>
struct DataType< ::gazebo_ros_plugin::Set_activationRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "gazebo_ros_plugin/Set_activationRequest";
  }

  static const char* value(const ::gazebo_ros_plugin::Set_activationRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::gazebo_ros_plugin::Set_activationRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 activation\n\
";
  }

  static const char* value(const ::gazebo_ros_plugin::Set_activationRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::gazebo_ros_plugin::Set_activationRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.activation);
      
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Set_activationRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::gazebo_ros_plugin::Set_activationRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::gazebo_ros_plugin::Set_activationRequest_<ContainerAllocator>& v)
  {
    s << indent << "activation: ";
    Printer<int64_t>::stream(s, indent + "  ", v.activation);
   
  }
};

} // namespace message_operations
} // namespace ros

#endif // GAZEBO_ROS_PLUGIN_MESSAGE_SET_ACTIVATIONREQUEST_H
