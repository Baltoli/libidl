#pragma once

#include <idl/specification.h>

namespace idl {

/**
 * In the future we might want to change the ownership semantics around the
 * Python interpreter stored by this object.
 */
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

  /**
   * This shouldn't be copyable - if you have an instance, it will behave the
   * same as any other instance.
   */
  code_generator(code_generator const&) = delete;

  /**
   * Similarly, don't allow this to be moved - keep one instance around and have
   * it be responsible for setting up and tearing down the interpreter.
   */
  code_generator(code_generator&&) = delete;

  std::string generate_from(specification const&) const;

private:
};

} // namespace idl
