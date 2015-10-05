// fib(n) = fib(n - 1) + fib(n - 2)

#include <cassert>
#include <cstdlib>
#include <iostream>

// the fib recursive call
int fib(const int&, long long& count);

int main(int argc, char* argv[]) {
  assert(argc == 2);
  long long count = 0;
  int target = atoi(argv[1]);

  int answer = fib(target, ++count);

  std::cout << answer << std::endl;
  std::cout << "Function calls: " << count << std::endl;
}

int fib(const int& n, long long& count) {
  assert(n >= 0);
 
  // base cases
  if (n <= 1)
    return n;

  // recursive case
  return fib(n - 1, ++count) + fib(n - 2, ++count);
}
