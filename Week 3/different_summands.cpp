#include <iostream>
#include <vector>

using std::vector;

vector<long long> optimal_summands(long long n) {
  vector<long long> summands;
  long long i = 1;
  while (true) {
    if (n <= (i*2)) {
      summands.push_back(n);
      return summands;
    } else {
      summands.push_back(i);
      n -= i;
      i++;
    }
  }
  return summands;
}

int main() {
  long long n;
  std::cin >> n;
  vector<long long> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
