#include "../include/easyfind.hpp"

template <typename T>
T &easyfind(T *array, int to_find) {
  for (int i = 0; array[i]; i++)
    if (to_find == array[i]) return (array[i]);
  throw NopeException();
}

const char *NopeException::what(void) const throw() {
  return "Error: the requested element doesn't exist";
}