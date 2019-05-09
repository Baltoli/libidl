#include <idl/slot.h>

#include <fmt/format.h>

namespace idl {

slot::slot(std::string os)
    : open_slot(os)
{
}

std::string slot::print() const
{
  using namespace fmt::literals;
  return "\"{}\""_format(open_slot);
}

} // namespace idl
