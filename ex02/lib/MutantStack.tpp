#include "../include/MutantStack.hpp"

// orthodox cannonical form
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src)
    : std::stack<T>(src) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src) {
  if (this != &src) {
    (void)src;
  }
  return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

// fonction
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
  return typename MutantStack<T>::iterator(this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
  return typename MutantStack<T>::iterator(this->c.end());
}

// iterator class

// orthodox cannonical form
template <typename T>
MutantStack<T>::iterator::iterator() : _it(NULL) {}

template <typename T>
MutantStack<T>::iterator::iterator(const typename MutantStack<T>::iterator &src)
    : _it(src._it) {}

template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator=(
    const typename MutantStack<T>::iterator &src) {
  if (this != &src) {
    _it = src._it;
  }
  return *this;
}

template <typename T>
MutantStack<T>::iterator::~iterator() {}

// constructor
template <typename T>
MutantStack<T>::iterator::iterator(
    const typename std::stack<T>::container_type::iterator &src)
    : _it(src) {}

// operator

template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator++() {
  return this->_it++;
}

template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator--() {
  return this->_it--;
}

template <typename T>
bool MutantStack<T>::iterator::operator!=(
    const typename MutantStack<T>::iterator &src) const {
  return this != &src;
}

template <typename T>
bool MutantStack<T>::iterator::operator==(
    const typename MutantStack<T>::iterator &src) const {
  return this == &src;
}

template <typename T>
T &MutantStack<T>::iterator::operator*() {}