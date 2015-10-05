// fib(n) = fib(n - 1) + fib(n - 2)

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <vector>

// the fib recursive call
void fib_rec(const int&, std::vector<long long>&, long long& count);

int main(int argc, char* argv[]) {
  assert(argc == 2);
  long long count = 0;
  int target = atoi(argv[1]);

  assert(target >= 0);
  std::vector<long long> memo(target + 1, -1);

  fib_rec(target, memo, ++count);
  
  for (int i = 0; i < target; ++i)
    std::cout << "[" << memo[i] << "]";

  std::cout << std::endl << "Function calls: " << count << std::endl;
}

void fib_rec(const int& n, std::vector<long long>& memo,  long long& count) {
  // base cases
  if (n <= 1) 
    memo[n] = n;
  
  // using memoization we will set the correct elements of our array
  if (memo[n - 2] == -1)
    fib_rec(n - 2, memo, ++count);

  if (memo[n - 1] == -1)
    fib_rec(n - 1, memo, ++count);

  // set the final element
  memo[n] = memo[n - 1] + memo[n - 2];
}
