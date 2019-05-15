#include <idl/code_generator.h>
#include <idl/internal/code_gen_src.h>

#include <string>

namespace idl {

code_generator::code_generator() { Py_Initialize(); }

code_generator::~code_generator() { Py_Finalize(); }

std::string code_generator::generate_from(specification const& s) const
{
  auto const& source = code_gen_src;
  PyRun_SimpleString(source.c_str());
  return "";
}

} // namespace idl
