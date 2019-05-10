#pragma once

#include <string>

namespace idl {

enum class atom_type {
  integer_type,
  float_type,
  vector_type,
  pointer_type,

  int_zero,
  float_zero,

  unused,
  not_numeric_constant,
  constant,
  preexecution,
  argument,
  instruction,

  same,
  distinct,
  block,

  dfg_edge,
  cfg_edge,
  cdg_edge,
  pdg_edge,

  first_operand,
  second_operand,
  third_operand,
  fourth_operand,

  first_successor,
  second_successor,
  third_successor,
  fourth_successor,

  dfg_dominate,
  dfg_postdom,
  dfg_dominate_strict,
  dfg_postdom_strict,

  cfg_dominate,
  cfg_postdom,
  cfg_dominate_strict,
  cfg_postdom_strict,

  pdg_dominate,
  pdg_postdom,
  pdg_dominate_strict,
  pdg_postdom_strict,

  dfg_not_dominate,
  dfg_not_postdom,
  dfg_not_dominate_strict,
  dfg_not_postdom_strict,

  cfg_not_dominate,
  cfg_not_postdom,
  cfg_not_dominate_strict,
  cfg_not_postdom_strict,

  pdg_not_dominate,
  pdg_not_postdom,
  pdg_not_dominate_strict,
  pdg_not_postdom_strict,

  incoming_value,

  dfg_blocked,
  cfg_blocked,
  pdg_blocked,

  function_attribute
};

std::string atom_type_to_string(atom_type t);

} // namespace idl
