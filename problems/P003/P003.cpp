#include <iostream>
#include <math.h>

int main(int argc, char const *argv[]) {
  int largest = 0;

  long long n = 600851475143;

  int factor = 2;
  while (factor <= n) {
    if (n % factor == 0) {
      if (factor > largest)
        largest = factor;

      std::cout << n << " divided by " << factor << " is ";

      n /= factor;

      std::cout << n << std::endl;

      factor = 2;
      continue;
    }

    factor++;
  }

  std::cout << largest;
  std::cin.get();

  return 0;
}