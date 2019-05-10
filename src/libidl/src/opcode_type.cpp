#include <idl/opcode_type.h>

namespace idl {

std::string opcode_type_to_string(opcode_type ot)
{
  switch (ot) {
  case opcode_type::branch:
    return "branch";
  }
}

} // namespace idl
