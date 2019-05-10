#pragma once

#include <string>

namespace idl {

/**
 * The different types of opcode that we can constrain instructions to have.
 *
 * TODO: fully populate this with all the different possible values.
 */
enum class opcode_type { branch };

std::string opcode_type_to_string(opcode_type);

} // namespace idl
