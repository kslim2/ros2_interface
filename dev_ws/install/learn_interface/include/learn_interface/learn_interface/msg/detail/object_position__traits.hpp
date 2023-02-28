// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from learn_interface:msg/ObjectPosition.idl
// generated code does not contain a copyright notice

#ifndef LEARN_INTERFACE__MSG__DETAIL__OBJECT_POSITION__TRAITS_HPP_
#define LEARN_INTERFACE__MSG__DETAIL__OBJECT_POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "learn_interface/msg/detail/object_position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace learn_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const ObjectPosition & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ObjectPosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ObjectPosition & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace learn_interface

namespace rosidl_generator_traits
{

[[deprecated("use learn_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const learn_interface::msg::ObjectPosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  learn_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use learn_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const learn_interface::msg::ObjectPosition & msg)
{
  return learn_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<learn_interface::msg::ObjectPosition>()
{
  return "learn_interface::msg::ObjectPosition";
}

template<>
inline const char * name<learn_interface::msg::ObjectPosition>()
{
  return "learn_interface/msg/ObjectPosition";
}

template<>
struct has_fixed_size<learn_interface::msg::ObjectPosition>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<learn_interface::msg::ObjectPosition>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<learn_interface::msg::ObjectPosition>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LEARN_INTERFACE__MSG__DETAIL__OBJECT_POSITION__TRAITS_HPP_
