#include "../include/MutantStack.hpp"

// orthodox cannonical form
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T>(src) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src) {
  if (this != &src) std::stack<T>::operator=(src);
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

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::rbegin() {
  return typename MutantStack<T>::iterator(this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::rend() {
  return typename MutantStack<T>::iterator(this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin() const {
  return typename MutantStack<T>::const_iterator(this->c.cbegin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend() const {
  return typename MutantStack<T>::const_iterator(this->c.cend());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::crbegin() const {
  return typename MutantStack<T>::const_iterator(this->c.crbegin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::crend() const {
  return typename MutantStack<T>::const_iterator(this->c.crend());
}

// iterator class

// orthodox cannonical form
template <typename T>
MutantStack<T>::iterator::iterator() : _it() {}

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
  ++_it;
  return *this;
}

template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator--() {
  --_it;
  return *this;
}

template <typename T>
bool MutantStack<T>::iterator::operator!=(
    const typename MutantStack<T>::iterator &src) const {
  return _it != src._it;
}

template <typename T>
bool MutantStack<T>::iterator::operator==(
    const typename MutantStack<T>::iterator &src) const {
  return _it == src._it;
}

template <typename T>
T &MutantStack<T>::iterator::operator*() {
  return *_it;
}

// const_iterator

// orthodox cannonical form
template <typename T>
MutantStack<T>::const_iterator::const_iterator() : _it() {}

template <typename T>
MutantStack<T>::const_iterator::const_iterator(
    const typename MutantStack<T>::const_iterator &src)
    : _it(src._it) {}

template <typename T>
typename MutantStack<T>::const_iterator &
MutantStack<T>::const_iterator::operator=(
    const typename MutantStack<T>::const_iterator &src) {
  if (this != &src) {
    _it = src._it;
  }
  return *this;
}

template <typename T>
MutantStack<T>::const_iterator::~const_iterator() {}

// constructor
template <typename T>
MutantStack<T>::const_iterator::const_iterator(
    const typename std::stack<T>::container_type::const_iterator &src)
    : _it(src) {}

// operator

template <typename T>
typename MutantStack<T>::const_iterator &
MutantStack<T>::const_iterator::operator++() {
  ++_it;
  return *this;
}

template <typename T>
typename MutantStack<T>::const_iterator &
MutantStack<T>::const_iterator::operator--() {
  --_it;
  return *this;
}

template <typename T>
bool MutantStack<T>::const_iterator::operator!=(
    const typename MutantStack<T>::const_iterator &src) const {
  return _it != src._it;
}

template <typename T>
bool MutantStack<T>::const_iterator::operator==(
    const typename MutantStack<T>::const_iterator &src) const {
  return _it == src._it;
}

template <typename T>
T &MutantStack<T>::const_iterator::operator*() {
  return *_it;
}
