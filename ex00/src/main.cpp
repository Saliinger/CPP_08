#include <iostream>

#include "../include/easyfind.hpp"

int main() {
  // Test with integer array
  std::cout << "=== Testing easyfind with integer array ===" << std::endl;
  int intArray[] = {1, 2, 3, 4, 5, 0};  // null-terminated

  try {
    int &found = easyfind(intArray, 3);
    std::cout << "Found element: " << found << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    int &found = easyfind(intArray, 10);
    std::cout << "Found element: " << found << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Searching for 10: " << e.what() << std::endl;
  }

  // Test with character array
  std::cout << "\n=== Testing easyfind with character array ===" << std::endl;
  char charArray[] = {'a', 'b', 'c', 'd', 'e', '\0'};

  try {
    char &found = easyfind(charArray, 'c');
    std::cout << "Found character: " << found << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    char &found = easyfind(charArray, 'z');
    std::cout << "Found character: " << found << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Searching for 'z': " << e.what() << std::endl;
  }

  // Test with another integer array
  std::cout << "\n=== Testing easyfind with different integer array ==="
            << std::endl;
  int largerArray[] = {10, 20, 30, 40, 50, 60, 70, 0};

  try {
    int &found = easyfind(largerArray, 30);
    std::cout << "Found element: " << found << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    int &found = easyfind(largerArray, 100);
    std::cout << "Found element: " << found << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Searching for 100: " << e.what() << std::endl;
  }

  std::cout << "\n=== Testing modification through reference ===" << std::endl;
  try {
    int &found = easyfind(intArray, 5);
    std::cout << "Original value: " << found << std::endl;
    found = 99;
    std::cout << "Modified value: " << found << std::endl;
    std::cout << "Array element is now: " << intArray[4] << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  // Test edge case: empty array (just null terminator)
  std::cout << "\n=== Testing with empty array ===" << std::endl;
  int emptyArray[] = {0};
  try {
    int &found = easyfind(emptyArray, 1);
    std::cout << "Found element: " << found << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Searching in empty array: " << e.what() << std::endl;
  }

  return 0;
}