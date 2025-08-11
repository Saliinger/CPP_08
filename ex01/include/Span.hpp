#pragma once

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class Span {
 private:
  unsigned int _size;
  unsigned int _len;
  std::vector<int> _array;

 public:
  // orthodox cannonical form
  Span();
  Span(const Span &src);
  Span &operator=(const Span &src);
  ~Span();

  // constructor
  Span(unsigned int size);

  // functions
  long shortestSpan() const;
  long longestSpan() const;
  void addNumber(int n);

  template <typename T>
  void addNumber(T n1, T n2) {
    unsigned int len = static_cast<unsigned int>(std::distance(n1, n2));
    if (len + _len  <= _size) {
      _array.insert(_array.end(), n1, n2);
      _len += len;
    } else
      throw OverflowException();
  }

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
