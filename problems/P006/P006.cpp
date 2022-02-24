#include <iostream>

int main() {
  int N = 100;

  long long sum_sq = 0;
  long long sq_sum = 101 * 101 * 50 * 50;

  for (int i = 1; i <= N; i++) {
    sum_sq += (i * i);
  }

  std::cout << sq_sum - sum_sq;

  return 0;
}