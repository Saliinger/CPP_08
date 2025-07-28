#include "../include/Span.hpp"

int main() {
  Span sp = Span(12);

  // sp.show();

  sp.addNumbers(0, 4);

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