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

  int i;
  bool found;
  while (true) {
    largest += 20;
    found = true;

    for (i = 19; i > 1; i--) {
      if (largest % i != 0) {
        found = false;
        break;
      }
    }

    if (found)
      break;
  }

  std::cout << largest;
  std::cin.get();

  return 0;
}