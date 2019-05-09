#include <idl/atom.h>

#include <fmt/format.h>

namespace idl {

atom::atom(atom_type at, std::vector<slot> ss)
    : type(at)
    , slots(ss)
{
}

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
