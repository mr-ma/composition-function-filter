#ifndef FUNCTIONFILTER_FUNCTIONMARKER_HPP
#define FUNCTIONFILTER_FUNCTIONMARKER_HPP
#include <function-filter/Info.hpp>
#include <llvm/IR/Function.h>
#include <llvm/IR/Module.h>
#include <llvm/Pass.h>
#include <unordered_set>

class FunctionMarkerPass : public llvm::ModulePass {
public:
  static char ID;

public:
  FunctionMarkerPass() : llvm::ModulePass(ID) {}
  bool runOnModule(llvm::Module& M) override;
  virtual void getAnalysisUsage(llvm::AnalysisUsage& AU) const override;
  FunctionInformation* get_functions_info();

private:
  FunctionInformation m_functions_info;
};
#endif // FUNCTIONFILTER_FUNCTIONMARKER_HPP
