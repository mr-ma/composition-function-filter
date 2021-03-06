#include <fstream>
#include <function-filter/Marker.hpp>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Support/Debug.h>
#include <llvm/Support/raw_ostream.h>

void FunctionMarkerPass::getAnalysisUsage(llvm::AnalysisUsage& AU) const { AU.setPreservesAll(); }
char FunctionMarkerPass::ID = 0;

bool FunctionMarkerPass::runOnModule(llvm::Module& M) {
  llvm::dbgs() << "In mark function pass\n";
  this->m_functions_info.init();
  return false;
}
FunctionInformation* FunctionMarkerPass::get_functions_info() { return &(this->m_functions_info); }
static llvm::RegisterPass<FunctionMarkerPass> X("marker-func", "Marks functions in a given file as assert functions");
