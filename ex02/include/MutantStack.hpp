#pragma once

#include <iostream>

template <typename T>
class MutantStack : public std::stack {
 public:
  // orthodox cannonical form
  MutantStack();
  MutantStack(const MutantStack &src);
  MutantStack &operator=(const MutantStack &src);
  ~MutantStack();

  // function
  int iterator();
};

#include "../lib/MutantStack.tpp"