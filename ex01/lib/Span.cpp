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
long Span::shortestSpan() const {
  if (_len < 2) throw NoSpanException();

  std::vector<int> sorted(_array);
  std::sort(sorted.begin(), sorted.end());

  long span = std::numeric_limits<int>::max();

  for (unsigned int i = 0; i < _len; i++) {
    for (unsigned int j = 0; j < _len; j++) {
        if(sorted[j] - sorted[i] < span && i != j)
          span = sorted[j] - sorted[i];
    }
  }

  return span;
}

long Span::longestSpan() const {
  if (_len < 2) throw NoRangeException();
  return *std::max_element(_array.begin(), _array.end()) -
         *std::min_element(_array.begin(), _array.end());
}

void Span::addNumber(int n) {
  if (_len < _size) {
    _array.push_back(n);
    _len++;
  } else
    throw OverflowException();
}

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