#pragma once

#include <idl/internal/code_gen_src.h>
#include <idl/specification.h>

#include <Python.h>

namespace idl {

class code_generator {
public:
  /**
   * Construct a new code generator that can turn an IDL specification into c++
   * code to be JIT compiled.
   *
   * This constructor is responsible for launching a python interpreter and
   * setting up the state required to use it, so it might be expensive to call.
   */
  code_generator();

  /**
   * Shut down the python interpreter when we're done generating code.
   */
  ~code_generator();

  std::string generate_from(specification const&) const;

private:
};

} // namespace idl
