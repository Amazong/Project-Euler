#include <iostream>
#include <vector>

bool has_500_divisors(long long n);

int main() {
  long long n = 0;
  long long i = 0;

  while (!has_500_divisors(n)) {
    n += ++i;
  }

  std::cout << n << std::endl;
}

bool has_500_divisors(long long n) {
  std::vector<long long> divs;

  long long lim = n / 2;
  for (long long i = 1; i < lim; i++) {
    if (n % i == 0) {
      divs.push_back(i);
      divs.push_back(n / i);
    }
  }

  return divs.size() > 500;
}