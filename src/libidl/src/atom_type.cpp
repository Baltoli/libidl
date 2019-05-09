#include <idl/atom_type.h>

namespace idl {

std::string atom_type_to_string(atom_type t)
{
  switch (t) {
  case atom_type::integer_type:
    return "ConstraintIntegerType";
  case atom_type::float_type:
    return "ConstraintFloatType";
  case atom_type::vector_type:
    return "ConstraintVectorType";
  case atom_type::pointer_type:
    return "ConstraintPointerType";

  case atom_type::int_zero:
    return "ConstraintIntZero";
  case atom_type::float_zero:
    return "ConstraintFloatZero";

  case atom_type::unused:
    return "ConstraintUnused";
  case atom_type::not_numeric_constant:
    return "ConstraintNotNumericConstant";
  case atom_type::constant:
    return "ConstraintConstant";
  case atom_type::preexecution:
    return "ConstraintPreexecution";
  case atom_type::argument:
    return "ConstraintArgument";
  case atom_type::instruction:
    return "ConstraintInstruction";

  case atom_type::indir_opcode_1:
    return "ConstraintIndirOpcode1";
  case atom_type::indir_opcode_2:
    return "ConstraintIndirOpcode2";
  case atom_type::opcode:
    return "ConstraintOpcode";

  case atom_type::same:
    return "ConstraintSame";
  case atom_type::distinct:
    return "ConstraintDistinct";
  case atom_type::block:
    return "ConstraintBlock";

  case atom_type::dfg_edge:
    return "ConstraintDFGEdge";
  case atom_type::cfg_edge:
    return "ConstraintCFGEdge";
  case atom_type::cdg_edge:
    return "ConstraintCDGEdge";
  case atom_type::pdg_edge:
    return "ConstraintPDGEdge";

  case atom_type::first_operand:
    return "ConstraintFirstOperand";
  case atom_type::second_operand:
    return "ConstraintSecondOperand";
  case atom_type::third_operand:
    return "ConstraintThirdOperand";
  case atom_type::fourth_operand:
    return "ConstraintFourthOperand";

  case atom_type::first_successor:
    return "ConstraintFirstSuccessor";
  case atom_type::second_successor:
    return "ConstraintSecondSuccessor";
  case atom_type::third_successor:
    return "ConstraintThirdSuccessor";
  case atom_type::fourth_successor:
    return "ConstraintFourthSuccessor";

  case atom_type::dfg_dominate:
    return "ConstraintDFGDominate";
  case atom_type::dfg_postdom:
    return "ConstraintDFGPostdom";
  case atom_type::dfg_dominate_strict:
    return "ConstraintDFGDominateString";
  case atom_type::dfg_postdom_strict:
    return "ConstraintDFGPostdomStrict";

  case atom_type::cfg_dominate:
    return "ConstraintCFGDominate";
  case atom_type::cfg_postdom:
    return "ConstraintCFGPostdom";
  case atom_type::cfg_dominate_strict:
    return "ConstraintCFGDominateStrict";
  case atom_type::cfg_postdom_strict:
    return "ConstraintCFGPostdomStrict";

  case atom_type::pdg_dominate:
    return "ConstraintPDGDominate";
  case atom_type::pdg_postdom:
    return "ConstraintPDGPostdom";
  case atom_type::pdg_dominate_strict:
    return "ConstraintPDGDominateStrict";
  case atom_type::pdg_postdom_strict:
    return "ConstraintPDGPostdomStrict";

  case atom_type::dfg_not_dominate:
    return "ConstraintDFGNotDominate";
  case atom_type::dfg_not_postdom:
    return "ConstraintDFGNotPostdom";
  case atom_type::dfg_not_dominate_strict:
    return "ConstraintDFGNotDominateStrict";
  case atom_type::dfg_not_postdom_strict:
    return "ConstraintDFGNotPostdomStrict";

  case atom_type::cfg_not_dominate:
    return "ConstraintCFGNotDominate";
  case atom_type::cfg_not_postdom:
    return "ConstraintCFGNotPostdom";
  case atom_type::cfg_not_dominate_strict:
    return "ConstraintCFGNotDominateStrict";
  case atom_type::cfg_not_postdom_strict:
    return "ConstraintCFGNotPostdomStrict";

  case atom_type::pdg_not_dominate:
    return "ConstraintPDGNotDominate";
  case atom_type::pdg_not_postdom:
    return "ConstraintPDGNotPostdom";
  case atom_type::pdg_not_dominate_strict:
    return "ConstraintPDGNotDominateStrict";
  case atom_type::pdg_not_postdom_strict:
    return "ConstraintPDGNotPostdomStrict";

  case atom_type::incoming_value:
    return "ConstraintIncomingValue";

  case atom_type::dfg_blocked:
    return "ConstraintDFGBlocked";
  case atom_type::cfg_blocked:
    return "ConstraintCFGBlocked";
  case atom_type::pdg_blocked:
    return "ConstraintPDGBlocked";

  case atom_type::function_attribute:
    return "ConstraintFunctionAttribute";
  }
}

} // namespace idl
