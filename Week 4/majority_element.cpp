#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) {
    return a[left];
  } else if (left + 1 == right) {
    if (a[left] == a[right]) {
      return a[left];
    } else {
      return -1; // -1 represents NO_MAJORITY
    }
  } else {
    int l = get_majority_element(a, left, int((right-left)/2)+left);
    // std::cout << "Function call with left: " << left << " and right: " << int((right-left)/2)+left << " returns: " << l << std::endl;
    int r = get_majority_element(a, int((right-left)/2)+left+1, right);
    // std::cout << "Function call with left: " << int((right-left)/2)+left+1 << " and right: " << right << " returns: " << r << std::endl;
    if (l != -1) {
      int count = 0;
      for (int i = left; i <= right; i++) {
        if (a[i] == l) {
          count++;
        }
      }
      // std::cout << "Checking value " << l << " in range of " << left << " to " << right << " returns count: " << count << " comparing to " << int((right-left)/2) << std::endl;
      if (count > int((right-left+1)/2)) {
        return l;
      }
    }
    if (r != -1) {
      int count = 0;
      for (int i = left; i <= right; i++) {
        if (a[i] == r) {
          count++;
        }
      }
      // std::cout << "Checking value " << r << " in range of " << left << " to " << right << " returns count: " << count << " comparing to " << int((right-left)/2) << std::endl;
      if (count > int((right-left+1)/2)) {
        return r;
      }
    }
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()-1) != -1) << '\n';
}
