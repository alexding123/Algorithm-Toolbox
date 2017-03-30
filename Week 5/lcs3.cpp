#include <iostream>
#include <vector>

using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  // initialize 3D vector
  int values[a.size()+1][b.size()+1][c.size()+1];
  for (int i = 0; i <= a.size(); i++)
    for (int j = 0; j <= b.size(); j++) 
      values[i][j][0] = 0;
  for (int i = 0; i <= a.size(); i++)
    for (int j = 0; j <= c.size(); j++) 
      values[i][0][j] = 0;
  for (int i = 0; i <= b.size(); i++)
    for (int j = 0; j <= c.size(); j++) 
      values[0][i][j] = 0;
  
  for (int i = 1; i <= a.size(); i++) {
    for (int j = 1; j <= b.size(); j++) {
      for (int k = 1; k <= c.size(); k++) {
        if ((a[i-1] == b[j-1]) && (b[j-1] == c[k-1])) { // if match
          values[i][j][k] = values[i-1][j-1][k-1] + 1;
        } else {
          values[i][j][k] = std::max(values[i-1][j][k], std::max(values[i][j-1][k], values[i][j][k-1]));
        }
      }
    }
  }
  return values[a.size()][b.size()][c.size()];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
