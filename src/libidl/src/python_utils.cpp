#include <idl/internal/python_utils.h>

#include <stdexcept>

namespace idl::py {

code_gen_wrap::code_gen_wrap(PyObject* mod, std::string const& func_name)
{
  auto fn = PyObject_GetAttrString(mod, func_name.c_str());
  if (!fn) {
    throw std::runtime_error("Can't load named function from module");
  }

  if (!PyCallable_Check(fn)) {
    Py_DECREF(fn);
    throw std::runtime_error("Named attribute is not a callable");
  }

  func_ = fn;
}

code_gen_wrap::~code_gen_wrap() { Py_DECREF(func_); }

code_gen_wrap::code_gen_wrap(code_gen_wrap const& other)
    : func_(other.func_)
{
  Py_INCREF(func_);
}

code_gen_wrap& code_gen_wrap::operator=(code_gen_wrap other)
{
  using std::swap;
  swap(func_, other.func_);
  return *this;
}

std::string code_gen_wrap::operator()(std::string const&) const
{
  return "woop";
}

PyObject* module_from_source(std::string const& src)
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

} // namespace idl::py
