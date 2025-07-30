#include "../include/Span.hpp"

// orthodox cannonical form
Span::Span() : _size(0), _len(0) {}

Span::Span(const Span &src) {
  _size = src._size;
  _len = src._len;
  _array = src._array;
}

Span &Span::operator=(const Span &src) {
  if (this != &src) {
    _size = src._size;
    _len = src._len;
    _array = src._array;
  }
  return *this;
}

Span::~Span() {}

// construcor
Span::Span(unsigned int size) : _size(size), _len(0) {}


//////////////////////////// TODO

// funcitons
int Span::max() {}

int Span::min() {}

long Span::shortestSpan() {}

long Span::longestSpan() {}

void Span::addNumber(int n) {}

void Span::addNumbers(int n1, int n2) {}

void Span::show() const {
  for (unsigned int i = 0; i < _len; i++)
    std::cout << i << ": " << _array[i] << std::endl;
}

//////////////////////////// END TODO

const char *Span::OverflowException::what() const throw() {
  return "Error: no space left";
}

const char *Span::NoSpanException::what() const throw() {
  return "Error: no span";
}

const char *Span::NoRangeException::what() const throw() {
  return "Error: no range";
}