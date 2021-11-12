#include <iostream>
#include <vector>

bool is_prime(const int &c, const std::vector<int> &p_list) {
  for (auto it : p_list) {
    if (c % it == 0)
      return false;
  }

  return true;
}

int find_next_prime(int &starting_point, const std::vector<int> &p_list) {
  while (!is_prime(starting_point, p_list))
    starting_point++;

  return starting_point;
}

int main() {
  int prime = 2;

  std::vector<int> p_list;

  while (p_list.size() < 10000) {
    p_list.push_back(find_next_prime(prime, p_list));
  }

  return find_next_prime(prime, p_list);
}