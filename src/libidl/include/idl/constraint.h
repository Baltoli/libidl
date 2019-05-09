#pragma once

#include <idl/atom.h>
#include <idl/constraint.h>
#include <idl/generic_formatter.h>
#include <idl/slot.h>

#include <memory>
#include <string>
#include <vector>

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
  virtual std::string to_string() const = 0;
};

/**
 * Adapts an atom into the virtual constraint hierarchy.
 */
class atom_adaptor : public constraint {
public:
  atom_adaptor(atom);

  std::string to_string() const override;

private:
  atom atom_;
};

/**
 * A conjunction of constraints. Each sub-constraint must be satisfied for this
 * constraint to also be satisfied.
 */
class conjunction : public constraint {
public:
  template <typename... Operands>
  conjunction(Operands... ops)
  {
    (operands_.emplace_back(new Operands(ops)), ...);
  }

  std::string to_string() const override;

private:
  std::vector<std::unique_ptr<constraint>> operands_ = {};
};

} // namespace idl

USE_UP_TO_STRING_FORMAT(idl::constraint)

USE_TO_STRING_FORMAT(idl::constraint)
USE_TO_STRING_FORMAT(idl::atom_adaptor)
USE_TO_STRING_FORMAT(idl::conjunction)
