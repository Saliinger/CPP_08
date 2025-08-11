   #include "../include/easyfind.hpp"

template <typename T>
T &easyfind(T *array, int to_find) {
  typename T::iterator it;

  it = std::find(array.begin(), array.end(), to_find);
  if (it == array.end() && it != to_find) throw NopeException();
  return it;
}

const char *NopeException::what(void) const throw() {
  return "Error: the requested element doesn't exist";
}