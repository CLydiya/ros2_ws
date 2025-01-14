// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from test_custom_msg_srv:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef TEST_CUSTOM_MSG_SRV__MSG__DETAIL__NUM__STRUCT_HPP_
#define TEST_CUSTOM_MSG_SRV__MSG__DETAIL__NUM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__test_custom_msg_srv__msg__Num __attribute__((deprecated))
#else
# define DEPRECATED__test_custom_msg_srv__msg__Num __declspec(deprecated)
#endif

namespace test_custom_msg_srv
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Num_
{
  using Type = Num_<ContainerAllocator>;

  explicit Num_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num = 0ll;
    }
  }

  explicit Num_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num = 0ll;
    }
  }

  // field types and members
  using _num_type =
    int64_t;
  _num_type num;

  // setters for named parameter idiom
  Type & set__num(
    const int64_t & _arg)
  {
    this->num = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    test_custom_msg_srv::msg::Num_<ContainerAllocator> *;
  using ConstRawPtr =
    const test_custom_msg_srv::msg::Num_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<test_custom_msg_srv::msg::Num_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<test_custom_msg_srv::msg::Num_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      test_custom_msg_srv::msg::Num_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<test_custom_msg_srv::msg::Num_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      test_custom_msg_srv::msg::Num_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<test_custom_msg_srv::msg::Num_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<test_custom_msg_srv::msg::Num_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<test_custom_msg_srv::msg::Num_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__test_custom_msg_srv__msg__Num
    std::shared_ptr<test_custom_msg_srv::msg::Num_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__test_custom_msg_srv__msg__Num
    std::shared_ptr<test_custom_msg_srv::msg::Num_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Num_ & other) const
  {
    if (this->num != other.num) {
      return false;
    }
    return true;
  }
  bool operator!=(const Num_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Num_

// alias to use template instance with default allocator
using Num =
  test_custom_msg_srv::msg::Num_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace test_custom_msg_srv

#endif  // TEST_CUSTOM_MSG_SRV__MSG__DETAIL__NUM__STRUCT_HPP_
