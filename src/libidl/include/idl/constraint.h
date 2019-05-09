#pragma once

#include <idl/constraint.h>
#include <idl/slot.h>

#include <string>

namespace idl {

/**
 * Corresponds to an IDL constraint, which make up the top-level entities in the
 * specification for an idiom.
 *
 * There are a number of different constraint types - this class represents the
 * top of a virtual hierarchy of constrain types.
 */
class constraint {
public:
  /**
   * Get a string representation of this constraint. The returned string is not
   * pretty-printed, but can be dropped into an AST representation of a
   * specification to be used with the legacy IDL compiler.
   */
  virtual std::string print() const = 0;
};

} // namespace idl
