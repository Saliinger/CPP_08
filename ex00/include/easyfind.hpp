#pragma once

#include <algorithm>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T &container, int to_find);

template <typename T>
typename T::const_iterator easyfind(const T &container, int to_find);

class NopeException : public std::exception {
 public:
  virtual const char *what(void) const throw();
};

#include "../lib/easyfind.tpp"