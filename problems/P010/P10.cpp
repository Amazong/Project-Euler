#include <iostream>
#include <vector>

int main() {
  std::vector<int> primes{3};
  long long sum = 2 + 3;

  int i, j;
  bool pass;
  for (i = 6; i < 2000000; i += 6) {
    for (j = i - 1; j <= i + 1; j += 2) {
      pass = false;

      for (auto it : primes) {
        if (j % it == 0) {
          pass = true;
          break;
        }
      }

      if (!pass) {
        primes.push_back(j);
        sum += j;
      }
    }
  }

  std::cout << sum;

  return 0;
}