#pragma once

#include <idl/atom_type.h>
#include <idl/generic_formatter.h>
#include <idl/slot.h>

#include <vector>

namespace idl {

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
  template <typename... Slots>
  atom(atom_type, Slots...);

  std::string to_string() const;

private:
  atom_type type;
  std::vector<slot> slots;
};

template <typename... Slots>
atom::atom(atom_type at, Slots... ss)
    : type(at)
    , slots()
{
  (slots.push_back(ss), ...);
}

} // namespace idl

USE_TO_STRING_FORMAT(idl::atom)
