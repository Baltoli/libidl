#include <idl/constraint.h>

#include <fmt/format.h>

namespace idl {

atom_adaptor::atom_adaptor(atom a)
    : atom_(a)
{
}

std::string atom_adaptor::to_string() const { return atom_.to_string(); }

std::string conjunction::to_string() const
{
  using namespace fmt::literals;

  if (operands_.empty()) {
    return R"(("conjunction"))";
  } else {
    return R"(("conjunction", {}))"_format(fmt::join(operands_, ", "));
  }
}

std::string disjunction::to_string() const
{
  using namespace fmt::literals;

  if (operands_.empty()) {
    return R"(("disjunction"))";
  } else {
    return R"(("disjunction", {}))"_format(fmt::join(operands_, ", "));
  }
}

} // namespace idl
