#pragma once

#include <iostream>
#include <limits>

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
  void addNumber(int n);
  void addNumbers(int n1, int n2);
  int min();
  int max();

  // custom
  void show() const;

  // exception
  class OverflowException : public std::exception {
    const char *what() const throw();
  };

  class NoSpanException : public std::exception {
    const char *what() const throw();
  };

  class NoRangeException : public std::exception {
    const char *what() const throw();
  };
};

#include "../lib/Span.tpp"
