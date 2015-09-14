#include <iostream>
#include <cstdlib>
#include "AStack.hpp"

const int DEFAULT_STACK_SIZE = 5;

int main(int argc, char* argv[]) {
  int size;
  if (argc != 2 || (size = atoi(argv[1])) < 1)
    size = DEFAULT_STACK_SIZE;
  
  AStack<int> *as = new AStack<int>(size);
  for (int i = 0; i < size; ++i)
    as->push(i);
  
  for (int i = 0; i < size; ++i)
    std::cout << "[" << as->pop() << "]";
  std::cout << std::endl;
}
