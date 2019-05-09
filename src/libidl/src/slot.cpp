#include <idl/slot.h>

#include <fmt/format.h>

namespace idl {

slot::slot(std::string os)
    : open_slot(os)
{
}

std::string slot::to_string() const
{
  using namespace fmt::literals;
  return R"(("slotbase", "{}"))"_format(open_slot);
}

} // namespace idl
