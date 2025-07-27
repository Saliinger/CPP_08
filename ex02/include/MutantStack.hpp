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
    bool operator!=(const iterator &src) const;  // compare if not !=
    bool operator==(const iterator &src) const;  // compare if stricly equal
    T &operator*();                              // access the current node
  };

  class const_iterator {
   private:
    typename std::stack<T>::container_type::iterator
        _it;  // element to point at

   public:
    // orthodox cannonical form
    const_iterator();
    const_iterator(const const_iterator &src);
    const_iterator &operator=(const const_iterator &src);
    ~const_iterator();

    // constructor
    const_iterator(
        const typename std::stack<T>::container_type::const_iterator &src);

    // operator
    const_iterator &operator++();
    const_iterator &operator--();
    bool operator!=(const const_iterator &src) const;
    bool operator==(const const_iterator &src) const;
    T &operator*();
  };
  // function
  typename MutantStack<T>::iterator begin();  // get the first node
  typename MutantStack<T>::iterator end();    // get the last node
  typename MutantStack<T>::iterator rbegin();
  typename MutantStack<T>::iterator rend();
  typename MutantStack<T>::const_iterator cbegin() const;
  typename MutantStack<T>::const_iterator cend() const;
  typename MutantStack<T>::const_iterator crbegin() const;
  typename MutantStack<T>::const_iterator crend() const;
  // both of the previous function access the uderlying container in the
  // std::stack cause it's a composed class who use std::deque<T> so
  // std::deque got an iterator
};

#include "../lib/MutantStack.tpp"