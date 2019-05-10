#pragma once

#include <idl/atom.h>
#include <idl/constraint.h>
#include <idl/generic_formatter.h>
#include <idl/opcode_type.h>
#include <idl/slot.h>

#include <value_ptr/value_ptr.h>

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
  explicit atom_adaptor(atom);

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
  explicit conjunction(Operands... ops)
      : operands_()
  {
    (operands_.emplace_back(new Operands(ops)), ...);
  }

  std::string to_string() const override;

private:
  std::vector<bsc::value_ptr<constraint>> operands_;
};

/**
 * A disjunction of constraints. One of the sub-constraints must be satisfied
 * for this constraint to also be satisfied.
 */
class disjunction : public constraint {
public:
  template <typename... Operands>
  explicit disjunction(Operands... ops)
      : operands_()
  {
    (operands_.emplace_back(new Operands(ops)), ...);
  }

  std::string to_string() const override;

private:
  std::vector<bsc::value_ptr<constraint>> operands_;
};

/**
 * An inheritance constraint. This specifies that this constraint must satisfy
 * the full set of requirements that the constraint it inherits from does - this
 * will be able to be used with a renaming constraint to change the name of
 * slots from the inherited constraint.
 */
class inherit_from : public constraint {
public:
  template <typename Constraint>
  inherit_from(Constraint c);

  inherit_from(bsc::value_ptr<constraint>);

  std::string to_string() const override;

private:
  bsc::value_ptr<constraint> constraint_;
};

template <typename Constraint>
inherit_from::inherit_from(Constraint c)
    : constraint_(bsc::make_val<Constraint>(c))
{
}

/**
 * Specifies that a the value filling a slot must have a particular opcode.
 */
class opcode : public constraint {
public:
  opcode(slot, opcode_type);

  std::string to_string() const override;

private:
  bsc::value_ptr<slot> slot_;
  opcode_type type_;
};

} // namespace idl

USE_VP_TO_STRING_FORMAT(idl::constraint)

USE_TO_STRING_FORMAT(idl::atom_adaptor)
USE_TO_STRING_FORMAT(idl::conjunction)
