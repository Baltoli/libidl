#pragma once

#include <Python.h>

#include <string>

namespace idl::py {

/**
 * Steals a reference to a python function, then exposes a callable interface
 * for code generator type functions (i.e. taking in a specification string and
 * returning another string representing the generated code).
 */
class code_gen_wrap {
public:
  /**
   * Construct a callable wrapper from a python module and a function name. Will
   * create a new reference to the function and store it.
   */
  code_gen_wrap(PyObject*, std::string const&);

  /**
   * Destroy the wrapper object, decrementing the reference count on the stored
   * function reference.
   */
  ~code_gen_wrap();

  /**
   * Copy constructor means that the other object will get the same reference as
   * this one but incremented (i.e. when this object goes out of scope, the
   * count won't reach 0).
   */
  code_gen_wrap(code_gen_wrap const&);

  code_gen_wrap& operator=(code_gen_wrap);

  std::string operator()(std::string const&) const;

private:
  PyObject* func_;
};

PyObject* module_from_source(std::string const&);

} // namespace idl::py
