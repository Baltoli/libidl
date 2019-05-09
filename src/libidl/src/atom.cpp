#include <idl/atom.h>

#include <fmt/format.h>

namespace idl {

std::string atom::to_string() const
{
  using namespace fmt::literals;
  if (slots.empty()) {
    return R"(("atom", ("{}")))"_format(atom_type_to_string(type));
  } else {
    return R"(("atom", ("{}", {})))"_format(
        atom_type_to_string(type), fmt::join(slots, ", "));
  }
}

} // namespace idl
