#ifndef _CUSTOM_PASSES_HPP_
#define _CUSTOM_PASSES_HPP_
#include "llvm/IR/PassManager.h"

namespace llvm {

class FunctionPass;
class ModulePass;

/* FlattenPass transforms all array accesses to be flat accesses to bare pointers.
   PreprocessorPass implements some additional peephole optimisations.
   ReplacerPass is the central part of this project, it uses the SMT based constraint solver to detect computational
   idioms in LLVM IR code. */
FunctionPass* createResearchFlangfixPass();
FunctionPass* createResearchPreprocessorPass();
ModulePass*   createResearchReplacerPass();
}

#endif
