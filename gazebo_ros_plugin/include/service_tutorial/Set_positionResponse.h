#ifndef SERVER_TUTORIAL_MESSAGE_SET_POSITIONRESPONSE_H
#define SERVER_TUTORIAL_MESSAGE_SET_POSITIONRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace server_tutorial
{
template <class ContainerAllocator>
struct Set_positionResponse_
{
  typedef Set_positionResponse_<ContainerAllocator> Type;

  Set_positionResponse_()
    : resu1(0)
    , resu2(0)  
    , resu3(0)
    , resu4(0)
    , resu5(0)
    , resu6(0){
    }
  Set_positionResponse_(const ContainerAllocator& _alloc)
    : resu1(0)
    , resu2(0)  
    , resu3(0)
    , resu4(0)
    , resu5(0)
    , resu6(0){
    }


   typedef int64_t _resu1_type;
  _resu1_type resu1;

     typedef int64_t _resu2_type;
  _resu2_type resu2;

     typedef int64_t _resu3_type;
  _resu3_type resu3;

     typedef int64_t _resu4_type;
  _resu4_type resu4;

     typedef int64_t _resu5_type;
  _resu5_type resu5;

     typedef int64_t _resu6_type;
  _resu6_type resu6;




  typedef boost::shared_ptr< ::server_tutorial::Set_positionResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::server_tutorial::Set_positionResponse_<ContainerAllocator> const> ConstPtr;

}; // struct Set_positionResponse_

typedef ::server_tutorial::Set_positionResponse_<std::allocator<void> > Set_positionResponse;

typedef boost::shared_ptr< ::server_tutorial::Set_positionResponse > Set_positionResponsePtr;
typedef boost::shared_ptr< ::server_tutorial::Set_positionResponse const> Set_positionResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::server_tutorial::Set_positionResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::server_tutorial::Set_positionResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace server_tutorial

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'server_tutorial': ['/home/kunal15595/ros/ros_ws/src/server_tutorial/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::server_tutorial::Set_positionResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::server_tutorial::Set_positionResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::server_tutorial::Set_positionResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::server_tutorial::Set_positionResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::server_tutorial::Set_positionResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::server_tutorial::Set_positionResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::server_tutorial::Set_positionResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b88405221c77b1878a3cbbfff53428d7";
  }

  static const char* value(const ::server_tutorial::Set_positionResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb88405221c77b187ULL;
  static const uint64_t static_value2 = 0x8a3cbbfff53428d7ULL;
};

template<class ContainerAllocator>
struct DataType< ::server_tutorial::Set_positionResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "server_tutorial/Set_positionResponse";
  }

  static const char* value(const ::server_tutorial::Set_positionResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::server_tutorial::Set_positionResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 resu1\n\
int64 resu2\n\
int64 resu3\n\
int64 resu4\n\
int64 resu5\n\
int64 resu6\n\
";
  }

  static const char* value(const ::server_tutorial::Set_positionResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::server_tutorial::Set_positionResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.sum1);
      stream.next(m.sum2);
      stream.next(m.sum3);
      stream.next(m.sum4);
      stream.next(m.sum5);
      stream.next(m.sum6);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Set_positionResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::server_tutorial::Set_positionResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::server_tutorial::Set_positionResponse_<ContainerAllocator>& v)
  {
    s << indent << "sum1: ";
    Printer<int64_t>::stream(s, indent + "  ", v.sum1);
    s << indent << "sum2: ";
    Printer<int64_t>::stream(s, indent + "  ", v.sum2);
    s << indent << "sum3: ";
    Printer<int64_t>::stream(s, indent + "  ", v.sum3);
    s << indent << "sum4: ";
    Printer<int64_t>::stream(s, indent + "  ", v.sum4);
    s << indent << "sum5: ";
    Printer<int64_t>::stream(s, indent + "  ", v.sum5);
    s << indent << "sum6: ";
    Printer<int64_t>::stream(s, indent + "  ", v.sum6);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SERVER_TUTORIAL_MESSAGE_SET_POSITIONRESPONSE_H
