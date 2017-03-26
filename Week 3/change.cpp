#include <iostream>

int get_change(int m) {
  int tens = (m - (m % 10)) / 10;
  int fives = (m % 10) / 5;
  int ones = m % 5;
  return tens + fives + ones;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
