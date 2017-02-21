#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<long long>& numbers) {
  long long a = 0; // a is always smaller/same as b
  long long b = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    if (numbers[i] > a) {
      if (numbers[i] >= b) {
        a = b;
        b = numbers[i];
      } else {
        a = numbers[i];
      }
    }
  }
  return a * b;
}


long long MaxPairwiseProductFast(const vector<long long>& numbers) {
  long long n = numbers.size();

  int max_index1 = -1;
  for (int i = 0; i < n; ++i)
    if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
      max_index1 = i;

  int max_index2 = -1;
  for (int j = 0; j < n; ++j)
    if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
      max_index2 = j;

  return ((long long)(numbers[max_index1])) * numbers[max_index2];
}


int main() {
    int n;
    cin >> n;
    vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}

