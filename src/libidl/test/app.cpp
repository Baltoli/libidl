#include <idl/idl.h>

#include <fmt/format.h>

#include <idl/code_gen_src.h>

using namespace idl;

int main()
{
  // clang-format off

  auto sese = conjunction(
    opcode(slot("precursor"), opcode_type::branch),
    atom_adaptor(atom(atom_type::cfg_edge, slot("precursor"), slot("begin"))),
    opcode(slot("end"), opcode_type::branch),
    atom_adaptor(atom(atom_type::cfg_edge, slot("end"), slot("successor"))),
    atom_adaptor(atom(atom_type::cfg_dominate, slot("begin"), slot("end"))),
    atom_adaptor(atom(atom_type::cfg_postdom, slot("end"), slot("begin"))),
    atom_adaptor(atom(atom_type::cfg_dominate_strict, slot("precursor"), slot("begin"))),
    atom_adaptor(atom(atom_type::cfg_postdom_strict, slot("successor"), slot("end"))),
    atom_adaptor(atom(atom_type::cfg_blocked, slot("begin"), slot("precursor"), slot("end"))),
    atom_adaptor(atom(atom_type::cfg_blocked, slot("successor"), slot("end"), slot("begin")))
  );

  auto loop = conjunction(
    inherit_from(sese),
    atom_adaptor(atom(atom_type::cfg_edge, slot("begin"), slot("end")))
  );

  // clang-format on

  auto spec = specification("Loop", loop);
  fmt::print("({},)\n", spec);

  fmt::print("{}\n", code_gen_src);
}
