// Generated by gencpp from file offb/location_id.msg
// DO NOT EDIT!


#ifndef OFFB_MESSAGE_LOCATION_ID_H
#define OFFB_MESSAGE_LOCATION_ID_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace offb
{
template <class ContainerAllocator>
struct location_id_
{
  typedef location_id_<ContainerAllocator> Type;

  location_id_()
    : hostel()
    , drone_id(0)  {
    }
  location_id_(const ContainerAllocator& _alloc)
    : hostel(_alloc)
    , drone_id(0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _hostel_type;
  _hostel_type hostel;

   typedef int32_t _drone_id_type;
  _drone_id_type drone_id;





  typedef boost::shared_ptr< ::offb::location_id_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::offb::location_id_<ContainerAllocator> const> ConstPtr;

}; // struct location_id_

typedef ::offb::location_id_<std::allocator<void> > location_id;

typedef boost::shared_ptr< ::offb::location_id > location_idPtr;
typedef boost::shared_ptr< ::offb::location_id const> location_idConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::offb::location_id_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::offb::location_id_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::offb::location_id_<ContainerAllocator1> & lhs, const ::offb::location_id_<ContainerAllocator2> & rhs)
{
  return lhs.hostel == rhs.hostel &&
    lhs.drone_id == rhs.drone_id;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::offb::location_id_<ContainerAllocator1> & lhs, const ::offb::location_id_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace offb

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::offb::location_id_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::offb::location_id_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::offb::location_id_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::offb::location_id_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::offb::location_id_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::offb::location_id_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::offb::location_id_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f8413624a35f58bf520d7fbe4c49b730";
  }

  static const char* value(const ::offb::location_id_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf8413624a35f58bfULL;
  static const uint64_t static_value2 = 0x520d7fbe4c49b730ULL;
};

template<class ContainerAllocator>
struct DataType< ::offb::location_id_<ContainerAllocator> >
{
  static const char* value()
  {
    return "offb/location_id";
  }

  static const char* value(const ::offb::location_id_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::offb::location_id_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string hostel\n"
"int32 drone_id\n"
;
  }

  static const char* value(const ::offb::location_id_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::offb::location_id_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.hostel);
      stream.next(m.drone_id);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct location_id_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::offb::location_id_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::offb::location_id_<ContainerAllocator>& v)
  {
    s << indent << "hostel: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.hostel);
    s << indent << "drone_id: ";
    Printer<int32_t>::stream(s, indent + "  ", v.drone_id);
  }
};

} // namespace message_operations
} // namespace ros

#endif // OFFB_MESSAGE_LOCATION_ID_H
