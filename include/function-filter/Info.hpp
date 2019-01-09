#ifndef FUNCTIONFILTER_INFO_HPP
#define FUNCTIONFILTER_INFO_HPP

#include <llvm/IR/Function.h>
#include <llvm/Support/Debug.h>
#include <llvm/Support/raw_ostream.h>
#include <unordered_set>

class FunctionInformation {
public:
  using FunctionSet = std::unordered_set<llvm::Function*>;

public:
  void add_function(llvm::Function* F);
  bool is_function(llvm::Function* F) const;
  const FunctionSet& get_functions() const;
  void init();

private:
  FunctionSet m_functions;
};
#endif // FUNCTIONFILTER_INFO_HPP
