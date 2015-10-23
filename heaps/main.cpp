#include <iostream>

#include "heap.hpp"

int main() {
  Heap h;
  for (int i = 0; i < 6; ++i)
    h.enqueue(10 - i);

  h.display();
}
