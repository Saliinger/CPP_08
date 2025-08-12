#include <vector>

#include "../include/easyfind.hpp"

int main() {
  std::vector<int> Array;

  for (unsigned int i = 0; i < 100000; i++) Array.push_back(i);

  try {
    std::vector<int>::iterator it = easyfind(Array, 55);
    std::cout << *it << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}