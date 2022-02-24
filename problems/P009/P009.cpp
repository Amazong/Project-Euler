#include <iostream>

int main() {
  int a, b, c;

  for (a = 1; a < 1000; a++) {
    for (b = a; b < 1000; b++) {
      for (c = b; c < 1000; c++) {
        if (a + b + c == 1000 && c * c == b * b + a * a) {
          std::cout << "a = " << a << "; b = " << b << "; c = " << c
                    << std::endl;
          std::cout << "a*b*c == " << a * b * c << std::endl;
        }
      }
    }
  }

  return 0;
}