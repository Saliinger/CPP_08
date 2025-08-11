#include "../include/Span.hpp"

int main() {
  Span sp = Span(10000);

  std::vector<int> Pizza;
  for (int i = 0; i < 10000; i++) {
    Pizza.push_back(i);
  }
  sp.addNumber(Pizza.begin(), Pizza.end());

  try {
    sp.addNumber(12);  // not supposed to work
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  // sp.show();

  try {
    std::cout << sp.shortestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::cout << sp.longestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }




  return 0;
}