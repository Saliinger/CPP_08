#pragma once

#include <iostream>

class Span {
 private:
  unsigned int _size;
  unsigned int _len;
  int *_array;

 public:
  // orthodox cannonical form
  Span();
  Span(const Span &src);
  Span &operator=(const Span &src);
  ~Span();

  // constructor
  Span(unsigned int size);

  // functions
  long shortestSpan();
  long longestSpan();
  void addnumber(int n);

  // exception
  class OverflowException : public std::exception {
    const char *what() const throw();
  };
};
