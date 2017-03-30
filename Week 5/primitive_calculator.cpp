#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;



vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  std::vector<int> values(n+1);
  values[1] = 0; // no use but reminds the fact that to get 1 you need 0 step (start with 1)
  for (int i = 2; i <= n; i++) {
    values[i] = values[i-1] + 1;
    if (i%2 == 0) {
      values[i] = std::min(values[i], values[i/2]+1);
    }
    if (i%3 == 0) {
      values[i] = std::min(values[i], values[i/3]+1);
    }
  }
  int i = n;
  while (i >= 1) {
    sequence.push_back(i);
    if (values[i] == values[i-1] + 1) {
      i--;
    } else if (i % 2 == 0 && (values[i] == values[i/2]+1)) {
      i/=2;
    } else if (i % 3 == 0 && (values[i] == values[i/3]+1)) {
      i/=3;
    } else {
      i--;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
