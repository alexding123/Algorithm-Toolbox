#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  vector<vector<int>> value;
  value.resize(w.size()+1, vector<int>(W+1, 0));
  // initialize first row and column
  for (int i = 0; i < W+1; i++)
    value[0][i] = 0;
  for (int i = 0; i < w.size()+1; i++)
    value[i][0] = 0;
  
  for (int i = 1; i <= w.size(); i++) {
    for (int j = 1; j <= W; j++) {
      value[i][j] = value[i-1][j]; // one more item, none picked
      int add_weight = value[i-1][j-w[i-1]] + w[i-1]; 
      if ((w[i-1] <= j) && (add_weight > value[i][j])) { // if possible to hold and is better option
        value[i][j] = add_weight;
      }
    }
  }
  /*for (int i = 0; i <= w.size(); i++) {
    for (int j = 0; j <= W; j++) {
     std::cout << value[i][j] << " ";
    }
    std::cout << std::endl;
  }*/

  return value[w.size()][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
