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
int Span::max() {
  if (_len < 2) throw NoSpanException();
  int max = std::numeric_limits<int>::min();

  for (unsigned int i = 0; i < _len; i++) {
    if (max < _array[i]) max = _array[i];
  }
  return max;
}

int Span::min() {
  int min = std::numeric_limits<int>::max();

  for (unsigned int i = 0; i < _len; i++) {
    if (min > _array[i]) min = _array[i];
  }
  return min;
}

long Span::shortestSpan() {
  if (_len < 2) throw NoSpanException();
  int span = std::numeric_limits<int>::max(), equal = 0;

  for (unsigned int i = 0; _array[i]; i++) {
    int s = _array[i] - this->min();
    
    // check for shorter span
    if (span > s && _array[i] != this->min()) span = s;

    // count number of the same number
    if (_array[i] == this->min()) equal++;
  }

  // check if there was other number to avoid
  // returning INT_MAX the default value
  if (equal == _len) throw NoSpanException();

  return span;
}

long Span::longestSpan() {
  if (_len < 2) throw NoSpanException();
  return this->max() - this->min();
}

void Span::addNumber(int n) {
  if (_len < _size) {
    _array[_len] = n;
    _len++;
  } else
    throw OverflowException();
}

const char *Span::OverflowException::what() const throw() {
  return "Error: no space left";
}

const char *Span::NoSpanException::what() const throw() {
  return "Error: no span";
}