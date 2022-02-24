#include <iostream>

void reverse(std::string &s) {
  char aux;
  int len = s.length() / 2;

  for (int i = 0; i < len; i++) {
    aux = s[i];
    s[i] = s[s.length() - 1 - i];
    s[s.length() - 1 - i] = aux;
  }
}

std::string times_2(const std::string &s) {
  int l = s.length();

  int carry = 0;
  std::string result;

  for (int i = l - 1; i >= 0; i--) {
    carry += 2 * (s[i] - '0');
    result.push_back((char)('0' + carry % 10));
    carry /= 10;
  }

  while (carry != 0) {
    result.push_back((char)('0' + carry % 10));
    carry /= 10;
  }

  reverse(result);

  return result;
}

std::string power_2(int n) {
  if (n == 0)
    return "1";

  return times_2(power_2(n - 1));
}

int sum_power_2(int n) {
  std::string p2 = power_2(n);

  // int l = p2.length();
  int sum = 0;
  for (auto digit : p2) {
    sum += (int)(digit - '0');
  }

  return sum;
}

int main() {
  std::cout << sum_power_2(1000) << std::endl;

  return 0;
}