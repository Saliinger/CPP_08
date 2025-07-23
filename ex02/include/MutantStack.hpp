#pragma once

#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  // orthodox cannonical form
  MutantStack();
  MutantStack(const MutantStack &src);
  MutantStack &operator=(const MutantStack &src);
  ~MutantStack();

  class iterator {
   private:
    typename std::stack<T>::container_type::iterator
        _it;  // element to point at

   public:
    // orthodox cannonical form
    iterator();
    iterator(const iterator &src);
    iterator &operator=(const iterator &src);
    ~iterator();

    // constructor
    iterator(const typename std::stack<T>::container_type::iterator &src);

    // operator
    iterator &operator++();                      // go next
    iterator &operator--();                      // go previous
    bool operator!=(const iterator &src) const;  // compare if not ==
    bool operator==(const iterator &src) const;  // compare if stricly equal
    T &operator*();                              // access the current node
  };

  // function
  typename MutantStack<T>::iterator begin();  // get the first node
  typename MutantStack<T>::iterator end();    // get the last node
  // both of the previous function access the uderlying container in the
  // std::stack cause it's a composed class who use std::deque<T> so std::deque
  // got an iterator
};

#include "../lib/MutantStack.tpp"