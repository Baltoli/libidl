#include <idl/code_generator.h>
#include <idl/internal/code_gen_src.h>
#include <idl/internal/python_utils.h>

#include <Python.h>

#include <string>

namespace idl {

code_generator::code_generator() { Py_Initialize(); }

code_generator::~code_generator() { Py_Finalize(); }

std::string code_generator::generate_from(specification const& s) const
{
  auto mod = py::module_from_source(code_gen_src);
  auto gen = py::code_gen_wrap(mod, "generate_cpp_code");

  return gen(s.to_string());
}

} // namespace idl
