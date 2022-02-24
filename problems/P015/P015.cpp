#include <iomanip>
#include <iostream>

// Result is given by:
//      40!/(20!20!) ==
//      == (40*39*...*21) / (20*19*...*1)

int main() {
  double prod = 1;

  for (int i = 0; i < 20; i++) {
    prod *= (double)(40 - i) / (20 - i);
  }

  std::cout << (long long int)prod << std::endl;

  return 0;
}