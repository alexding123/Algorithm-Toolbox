#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <climits>

using std::vector;
using std::string;
using std::max;
using std::min;
using namespace std;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

void get_minmax(int i, int j, vector<vector<long long>> &min, vector<vector<long long>> &max, vector<char> &symbols) {
  // initialize to the other extreme
  long long retMin = LLONG_MAX;
  long long retMax = LLONG_MIN;
  // find min and max
  for (int k = i; k < j; k++) {
    long long a = eval(max[i][k], max[k+1][j], symbols[k]);
    long long b = eval(max[i][k], min[k+1][j], symbols[k]);
    long long c = eval(min[i][k], max[k+1][j], symbols[k]);
    long long d = eval(min[i][k], min[k+1][j], symbols[k]);
    retMin = std::min(std::min(std::min(a, b), std::min(c, d)), retMin);
    retMax = std::max(std::max(std::max(a, b), std::max(c, d)), retMax);
  }
  min[i][j] = retMin;
  max[i][j] = retMax;
  return;
}

long long get_maximum_value(const string &exp) {
  // initialize
  vector<int> digits;
  vector<char> symbols;
  for (int i = 0; i < exp.size(); i+=2)
    digits.push_back(exp[i]-'0');
  for (int i = 1; i < exp.size(); i+=2) 
    symbols.push_back(exp[i]);

  // make max & min
  vector<vector<long long>> min;
  min.resize(digits.size(), vector<long long>(digits.size(), 0));
  vector<vector<long long>> max;
  max.resize(digits.size(), vector<long long>(digits.size(), 0));
  for (int i = 0; i < digits.size(); i++) { // initialize the diagonal
    min[i][i] = digits[i];
    max[i][i] = digits[i];
  }

  for (int d = 1; d < digits.size(); d++) { // initialize everything else
    for (int i = 0; i < (digits.size() - d); i++) {
      int j = i + d; 
      get_minmax(i, j, min, max, symbols);
    }
  }
  /*for (int i = 0; i < max.size(); i++) {
    for (int j = 0; j < max[0].size(); j++) {
      cout << max[i][j] << " ";
    }
    cout << endl;
  }
  for (int i = 0; i < max.size(); i++) {
    for (int j = 0; j < max[0].size(); j++) {
      cout << min[i][j] << " ";
    }
    cout << endl;
  }*/ // for testing
  return max[0][digits.size()-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
