#include "../include/Span.hpp"

// orthodox cannonical form
Span::Span() : _size(0), _len(0), _array(NULL) {}

Span::Span(const Span &src) { *this = src; }

Span &Span::operator=(const Span &src) {
  if (this != &src) {
    _size = src._size;
    _len = src._len;
    if (_array) delete[] _array;
    if (_size == 0) {
      _array = NULL;
      return *this;
    }
    _array = new int[_size];
    for (unsigned int i = 0; i < _size; i++) _array[i] = src._array[i];
  }
  return *this;
}

Span::~Span() {
  if (_array) delete[] _array;
  _array = NULL;
}

// construcor
Span::Span(unsigned int size) {
  _size = size;
  _len = 0;
  _array = new int[_size];
}

// funcitons
long Span::shortestSpan() {
  long span = 0;
  unsigned int i = 0;

  while (_array[i]) {
    unsigned int j = 0;
    while (_array[j]) {
      if (_array[i] - _array[j] < span) span = _array[i] - _array[j];
      j++;
    }
    i++;
  }
  return span;
}

long Span::longestSpan() {
  long span = 0;
  unsigned int i = 0;

  while (_array[i]) {
    unsigned int j = 0;
    while (_array[j]) {
      if (_array[i] - _array[j] > span) span = _array[i] - _array[j];
      j++;
    }
    i++;
  }
  return span;
}

void Span::addNumber(int n) {
  if (_len < _size) {
    _array[_len] = n;
    _len++;
  } else
    throw Span::OverflowException();
}

const char *Span::OverflowException::what() const throw() {
  return "Error: no space left";
}