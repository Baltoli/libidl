#include <idl/code_generator.h>

namespace idl {

code_generator::code_generator() {}

code_generator::~code_generator() {}

std::string code_generator::generate_from(specification const& s) const
{
  return s.to_string();
}

} // namespace idl
