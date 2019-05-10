#pragma once

#include <idl/constraint.h>
#include <idl/generic_formatter.h>

#include <value_ptr/value_ptr.h>

#include <string>

namespace idl {

class specification {
public:
  template <typename Constraint>
  specification(std::string, Constraint);

  std::string to_string() const;

private:
  bsc::value_ptr<constraint> constraint_;
  std::string name_;
};

template <typename Constraint>
specification::specification(std::string name, Constraint c)
    : name_(name)
    , constraint_(bsc::make_val<Constraint>(c))
{
}

} // namespace idl

USE_TO_STRING_FORMAT(idl::specification)
