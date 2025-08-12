#include "../include/easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int to_find) {
  typename T::iterator it =
      std::find(container.begin(), container.end(), to_find);
  if (it == container.end()) throw NopeException();
  return it;
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int to_find) {
  typename T::const_iterator it =
      std::find(container.begin(), container.end(), to_find);
  if (it == container.end()) throw NopeException();
  return it;
}

const char *NopeException::what(void) const throw() {
  return "Error: the requested element doesn't exist";
}