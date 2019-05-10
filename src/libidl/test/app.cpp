#include <idl/idl.h>

#include <fmt/format.h>

using namespace idl;

int main()
{
  auto a = atom(atom_type::dfg_dominate, slot("first"), slot("Seocnd"));
  auto c = conjunction(atom_adaptor(a), atom_adaptor(a));

  auto d = conjunction(inherit_from(c), atom_adaptor(a));
  auto s = specification("spec_name", d);
  fmt::print("{}\n", s);
}
