#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

void reverse(std::string &s) {
  char aux;
  int len = s.length() / 2;

  for (int i = 0; i < len; i++) {
    aux = s[i];
    s[i] = s[s.length() - 1 - i];
    s[s.length() - 1 - i] = aux;
  }
}

std::string sum_str(const std::string numbs[], const int &digits,
                    const int &N_NUMBS) {
  std::string s;
  int carry = 0;

  for (int d = digits - 1; d >= 0; --d) {
    for (int n = 0; n < N_NUMBS; ++n) {
      carry += (int)(numbs[n].at(d) - '0');
    }

    s.push_back((char)('0' + carry % 10));
    carry /= 10;
  }

  while (carry != 0) {
    s.push_back((char)('0' + carry % 10));
    carry /= 10;
  }

  reverse(s);

  return s;
}

int main() {
  std::ifstream fin("P13.in");

  if (!fin.is_open())
    return -1;

  std::string numbers[50];
  for (auto &number : numbers) {
    std::getline(fin, number);
  }

  std::cout << sum_str(numbers, 50, 50).substr(0, 10) << std::endl;

  return 0;
}

// int least(const int &a, const int &b) {
//     return a < b ? a : b;
// }
//
// int most(const int &a, const int &b) {
//     return a < b ? b : a;
// }
//
// std::string add_s(std::string &a, std::string &b) {
//     std::string res;
//     int len;
//
//     // The result will be reversed at first
//     int carry = 0, val, i;
//     len = least(a.size(), b.size());
//     for (i = 0; i < len; i++) {
//         val = carry + (int)(a[a.size() - 1 - i] - '0') + (int)(b[b.size() - 1
//         - i] - '0'); carry = val / 10; res.push_back(static_cast<char>('0' +
//         (val - carry * 10)));
//     }
//
//     // Get the remainder of the values
//     std::string * largest;
//     a.size() > b.size() ? largest = &a : largest = &b;
//     len = most(a.size(), b.size());
//     for (i = least(a.size(), b.size()); i < len; i++) {
//         val = carry + (int)((*largest)[largest->size() - 1 - i] - '0');
//         carry = val / 10;
//         res.push_back(static_cast<char>('0' + (val - carry * 10)));
//     }
//
//     // Reverse the string
//     len = res.size() / 2;
//     char aux;
//     for (int i = 0; i < len; i++) {
//         aux = res[i];
//         res[i] = res[res.size() - 1 - i];
//         res[res.size() - 1 - i] = aux;
//     }
//     return res;
// }
//
// std::string to_str(unsigned long long l) {
//     std::string s;
//
//     while (l != 0) {
//         s += static_cast<char>(l % 10 - '0');
//         l /= 10;
//     }
//
//     return s;
// }