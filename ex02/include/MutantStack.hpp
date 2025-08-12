#pragma once

#include <deque>
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  // orthodox cannonical form
  MutantStack();
  MutantStack(const MutantStack &src);
  MutantStack &operator=(const MutantStack &src);
  ~MutantStack();

  // definition
  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef
      typename std::stack<T>::container_type::const_iterator const_iterator;
  typedef typename std::stack<T>::container_type::reverse_iterator
      reverse_iterator;
  typedef typename std::stack<T>::container_type::const_reverse_iterator
      const_reverse_iterator;

  // function
  iterator begin() ;
  iterator end() ;

  reverse_iterator rbegin() ;
  reverse_iterator rend() ;

  const_iterator cbegin() const;
  const_iterator cend() const;

  const_reverse_iterator crbegin() const;
  const_reverse_iterator crend() const;
};

#include "../lib/MutantStack.tpp"