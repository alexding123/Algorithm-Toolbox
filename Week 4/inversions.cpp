#include <iostream>
#include <vector>

using std::vector;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  size_t leftCt = left;
  size_t rightCt = ave;
  size_t i = left;
  while ((leftCt < ave) || (rightCt < right)) {
    if (leftCt == ave) {
      b[i] = a[rightCt];
      rightCt++;
    } else if (rightCt == right) {
      b[i] = a[leftCt];
      leftCt++;
    } else {
      if (a[leftCt] <= a[rightCt]) {
        b[i] = a[leftCt];
        leftCt++;
      } else {
        b[i] = a[rightCt];
        rightCt++;
        number_of_inversions+= ave-leftCt;
      }
    }

    i++;
  }

  for (int j = left; j < right; j++) {
    a[j] = b[j];
  }
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
