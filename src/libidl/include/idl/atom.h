#pragma once

#include <idl/slot.h>

#include <vector>

namespace idl {

#include "atom_type.h"

/**
 * Similar to constraints, IDL specifies a set of possible atom types. Unlike
 * constraints, these cannot be nested and so represent the leaf nodes in the
 * AST.
 *
 * The only difference between types of atom is the named constraint type they
 * represent. The slots contained in an atom are variadic (can have multiple).
 */
class atom {
public:
  std::string print() const;

private:
  atom_type type;
  std::vector<slot> slots;
};

} // namespace idl
