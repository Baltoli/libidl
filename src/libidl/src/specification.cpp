#include <idl/specification.h>

#include <fmt/format.h>

namespace idl {

std::string specification::to_string() const
{
  using namespace fmt::literals;

  return R"(("specification", "{}", {}))"_format(name_, constraint_);
}

} // namespace idl
