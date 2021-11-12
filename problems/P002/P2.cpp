#include <iostream>

int main(int argc, char const *argv[]) {
  int sum = 0;
  int f1 = 1, f2 = 1, aux;

  while (f1 < 4000000) {
    aux = f1 + f2;
    f2 = f1;
    f1 = aux;

    if (f1 % 2 == 0)
      sum += f1;
  }

  std::cout << sum;
  std::cin.get();

  return 0;
}