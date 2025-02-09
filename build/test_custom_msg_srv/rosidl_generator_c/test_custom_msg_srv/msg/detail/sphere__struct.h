// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from test_custom_msg_srv:msg/Sphere.idl
// generated code does not contain a copyright notice

#ifndef TEST_CUSTOM_MSG_SRV__MSG__DETAIL__SPHERE__STRUCT_H_
#define TEST_CUSTOM_MSG_SRV__MSG__DETAIL__SPHERE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'center'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Sphere in the package test_custom_msg_srv.
typedef struct test_custom_msg_srv__msg__Sphere
{
  geometry_msgs__msg__Point center;
  double radius;
} test_custom_msg_srv__msg__Sphere;

// Struct for a sequence of test_custom_msg_srv__msg__Sphere.
typedef struct test_custom_msg_srv__msg__Sphere__Sequence
{
  test_custom_msg_srv__msg__Sphere * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} test_custom_msg_srv__msg__Sphere__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEST_CUSTOM_MSG_SRV__MSG__DETAIL__SPHERE__STRUCT_H_
