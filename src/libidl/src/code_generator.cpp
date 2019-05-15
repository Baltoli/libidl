#include <idl/code_generator.h>
#include <idl/internal/code_gen_src.h>

#include <string>

namespace idl {

code_generator::code_generator() { Py_Initialize(); }

code_generator::~code_generator() { Py_Finalize(); }

std::string code_generator::generate_from(specification const& s) const
{
  auto mod = module_from_source(code_gen_src);
  auto func = PyObject_GetAttrString(mod, "generate_cpp_code");

  return "";
}

PyObject* code_generator::module_from_source(std::string const& src) const
{
  auto mod = PyModule_New("code_gen");
  if (!mod) {
    throw std::runtime_error("Couldn't create new python module");
  }

  PyModule_AddStringConstant(mod, "__file__", "");
  auto local_dict = PyModule_GetDict(mod);
  auto builtins = PyEval_GetBuiltins();
  PyDict_SetItemString(local_dict, "__builtins__", builtins);

  auto val = PyRun_String(src.c_str(), Py_file_input, local_dict, local_dict);
  if (!val) {
    throw std::runtime_error("Couldn't load Python module from source code");
  }

  Py_DECREF(val);
  return mod;
}

} // namespace idl
