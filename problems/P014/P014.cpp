#include <algorithm>
#include <iostream>
#include <vector>

struct largest_candidate {
  int n_steps;
  int number;
};

int n_steps_collatz(int i) {
  auto n = (unsigned long long)(i);
  int c = 0;

  while (n != 1) {
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = 3 * n + 1;
    }
    c++;
  }

  return c;
}

int main() {
  largest_candidate lc = {0, 0};

  int n_steps;
  for (int i = 1; i < 1000000; i++) {
    n_steps = n_steps_collatz(i);

    if (n_steps > lc.n_steps) {
      lc.n_steps = n_steps;
      lc.number = i;
    }
  }

  std::cout << lc.number << std::endl;

  return 0;
}