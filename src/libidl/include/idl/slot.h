#pragma once

#include <string>

namespace idl {

/**
 * Corresponds to an IDL slot, which identifies empty components of a solution
 * which are to be matched against values when the constraint system is solved.
 *
 * For now, slots are implemented to represent only simple open named slots,
 * with no indexing or member access. More complicated features will be added as
 * I need them.
 */
class slot {
public:
  slot(std::string);

  std::string print() const;

private:
  std::string open_slot;
};

} // namespace idl
