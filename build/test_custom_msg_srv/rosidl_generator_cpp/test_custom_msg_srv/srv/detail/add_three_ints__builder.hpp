// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from test_custom_msg_srv:srv/AddThreeInts.idl
// generated code does not contain a copyright notice

#ifndef TEST_CUSTOM_MSG_SRV__SRV__DETAIL__ADD_THREE_INTS__BUILDER_HPP_
#define TEST_CUSTOM_MSG_SRV__SRV__DETAIL__ADD_THREE_INTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "test_custom_msg_srv/srv/detail/add_three_ints__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace test_custom_msg_srv
{

namespace srv
{

namespace builder
{

class Init_AddThreeInts_Request_c
{
public:
  explicit Init_AddThreeInts_Request_c(::test_custom_msg_srv::srv::AddThreeInts_Request & msg)
  : msg_(msg)
  {}
  ::test_custom_msg_srv::srv::AddThreeInts_Request c(::test_custom_msg_srv::srv::AddThreeInts_Request::_c_type arg)
  {
    msg_.c = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_custom_msg_srv::srv::AddThreeInts_Request msg_;
};

class Init_AddThreeInts_Request_b
{
public:
  explicit Init_AddThreeInts_Request_b(::test_custom_msg_srv::srv::AddThreeInts_Request & msg)
  : msg_(msg)
  {}
  Init_AddThreeInts_Request_c b(::test_custom_msg_srv::srv::AddThreeInts_Request::_b_type arg)
  {
    msg_.b = std::move(arg);
    return Init_AddThreeInts_Request_c(msg_);
  }

private:
  ::test_custom_msg_srv::srv::AddThreeInts_Request msg_;
};

class Init_AddThreeInts_Request_a
{
public:
  Init_AddThreeInts_Request_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AddThreeInts_Request_b a(::test_custom_msg_srv::srv::AddThreeInts_Request::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_AddThreeInts_Request_b(msg_);
  }

private:
  ::test_custom_msg_srv::srv::AddThreeInts_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_custom_msg_srv::srv::AddThreeInts_Request>()
{
  return test_custom_msg_srv::srv::builder::Init_AddThreeInts_Request_a();
}

}  // namespace test_custom_msg_srv


namespace test_custom_msg_srv
{

namespace srv
{

namespace builder
{

class Init_AddThreeInts_Response_sum
{
public:
  Init_AddThreeInts_Response_sum()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::test_custom_msg_srv::srv::AddThreeInts_Response sum(::test_custom_msg_srv::srv::AddThreeInts_Response::_sum_type arg)
  {
    msg_.sum = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_custom_msg_srv::srv::AddThreeInts_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_custom_msg_srv::srv::AddThreeInts_Response>()
{
  return test_custom_msg_srv::srv::builder::Init_AddThreeInts_Response_sum();
}

}  // namespace test_custom_msg_srv

#endif  // TEST_CUSTOM_MSG_SRV__SRV__DETAIL__ADD_THREE_INTS__BUILDER_HPP_
