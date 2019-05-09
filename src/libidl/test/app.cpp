#include <idl/idl.h>

#include <fmt/format.h>

using namespace idl;

int main()
{
  auto a = atom(atom_type::dfg_dominate, slot("first"), slot("Seocnd"));
  fmt::print("{}\n", a);
}
