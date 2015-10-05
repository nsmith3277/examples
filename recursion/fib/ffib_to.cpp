// fib(n) = fib(n - 1) + fib(n - 2)

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <vector>

// the fib helper function
int fib(const int&, long long& count);

// the fib recursive call
int fib_rec(const int&, std::vector<int>&, long long& count);

int main(int argc, char* argv[]) {
  assert(argc == 2);
  long long count = 0;
  int target = atoi(argv[1]);

  for (int i = 0; i <= target; ++i)
    std::cout << "[" << fib(i, ++count) << "]";

  std::cout << std::endl << "Function calls: " << count << std::endl;
}

int fib(const int& n, long long& count) {
  // create the memoization vector
  std::vector<int> memo(n + 1, -1);
  return fib_rec(n, memo, ++count);
}

int fib_rec(const int& n, std::vector<int>& memo,  long long& count) {
  assert(n >= 0);
 
  // base cases
  if (n <= 1)
    return n;

  // recursively calculate the elements for memoization
  if (memo[n - 1] == -1)
    memo[n - 1] = fib_rec(n - 1, memo, ++count);

  if (memo[n - 2] == -1)
    memo[n - 2] = fib_rec(n - 2, memo, ++count);

  // recursive case
  return memo[n - 1] + memo[n - 2];
}
