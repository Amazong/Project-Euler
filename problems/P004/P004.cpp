#include <iostream>

bool is_palindrome(int &n) {
  std::string s = std::to_string(n);

  for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
    if (s[i] != s[j])
      return false;
  }

  return true;
}

int main(int argc, char const *argv[]) {
  int largest = 0;

  // Brute force method, for the sake of benchmarking
  int n;
  for (int i = 999; i > 100; i--) {
    for (int j = 999; j > 100; j--) {
      n = i * j;
      if (n > largest && is_palindrome(n))
        largest = n;
    }
  }

  std::cout << largest;
  std::cin.get();

  return 0;
}