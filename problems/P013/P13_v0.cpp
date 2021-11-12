#include <cstdlib>
#include <fstream>
#include <iostream>

std::string add_s(std::string &a, std::string &b);

int main() {
  std::ifstream fin("P13.in");

  if (!fin.is_open())
    return -1;

  std::string numbers[50];
  std::string res;
  for (auto &number : numbers) {
    std::getline(fin, number);
    res = add_s(res, number);
  }

  std::cout << res << std::endl;

  return 0;
}

int least(const int &a, const int &b) { return a < b ? a : b; }

int most(const int &a, const int &b) { return a < b ? b : a; }

std::string add_s(std::string &a, std::string &b) {
  std::string res;
  int len;

  // The result will be reversed at first
  int carry = 0, val, i;
  len = least(a.size(), b.size());
  for (i = 0; i < len; i++) {
    val = carry + (int)(a[a.size() - 1 - i] - '0') +
          (int)(b[b.size() - 1 - i] - '0');
    carry = val / 10;
    res.push_back(static_cast<char>('0' + (val - carry * 10)));
  }

  // Get the remainder of the values
  std::string *largest;
  a.size() > b.size() ? largest = &a : largest = &b;
  len = most(a.size(), b.size());
  for (i = least(a.size(), b.size()); i < len; i++) {
    val = carry + (int)((*largest)[largest->size() - 1 - i] - '0');
    carry = val / 10;
    res.push_back(static_cast<char>('0' + (val - carry * 10)));
  }

  // Reverse the string
  len = res.size() / 2;
  char aux;
  for (int i = 0; i < len; i++) {
    aux = res[i];
    res[i] = res[res.size() - 1 - i];
    res[res.size() - 1 - i] = aux;
  }
  return res;
}