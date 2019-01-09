#ifndef FUNCTIONFILTER_FILTER_HPP
#define FUNCTIONFILTER_FILTER_HPP

#include <function-filter/Info.hpp>
#include <llvm/IR/Function.h>
#include <llvm/Pass.h>
#include <unordered_set>

class FunctionFilterPass : public llvm::ModulePass {
public:
  static char ID;

public:
  FunctionFilterPass() : llvm::ModulePass(ID) {}

public:
  bool runOnModule(llvm::Module& M) override;
  virtual void getAnalysisUsage(llvm::AnalysisUsage& AU) const override;
  FunctionInformation* get_functions_info();
  void loadFile(llvm::Module& M, std::string file_name);

private:
  FunctionInformation m_functions_info;
};

#endif // FUNCTIONFILTER_FILTER_HPP