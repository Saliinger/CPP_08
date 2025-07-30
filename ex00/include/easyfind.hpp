#pragma once

#include <iostream>
#include <algorithm>

template <typename T>
T &easyfind(T *array, int to_find);

class NopeException : public std::exception {
 public:
  virtual const char *what(void) const throw();
};

#include "../lib/easyfind.tpp"