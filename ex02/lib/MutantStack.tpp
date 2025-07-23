#include "../include/MutantStack.hpp"

// orthodox cannonical form
template <typename T>
MutantStack<T>::MutantStack() : public std::stack<T> {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src)
    : public std::stack<T>(src) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

// fonction
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
  return iterator(this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
  return iterator(this->c.begin());
}

// iterator class

template <typename T>
MutantStack<T>::iterator::iterator() {}

template <typename T>
MutantStack<T>::iterator::iterator(
    const typename MutantStack<T>::iterator &src) {}

template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator=(
    const typename MutantStack<T>::iterator &src) {}
