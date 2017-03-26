#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

struct Greater {
  bool operator() (const string lx, const string rx) const
  {
    string a = lx + rx;
    return (a.compare(rx+lx) > 0);
  }
};

string largest_number(vector<string> a) {
  std::sort(a.begin(), a.end(), Greater());
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
