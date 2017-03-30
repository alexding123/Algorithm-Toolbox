#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int edit_distance(const string &str1, const string &str2) {
  vector<vector<int>> value;
  value.resize(str1.length()+1, vector<int>(str2.length()+1, 0)); // initialize 2D vector
  for (int i = 0; i <= str1.length(); i++)
    value[i][0] = i;
  for (int i = 0; i <= str2.length(); i++)
    value[0][i] = i;

  for (int i = 1; i <= str1.length(); i++) {
    for (int j = 1; j <= str2.length(); j++) {
      if (str1[i-1] == str2[j-1]) { // match
        value[i][j] = std::min(std::min(value[i][j-1]+1, value[i-1][j]+1), value[i-1][j-1]);
      } else { // mismatch
        value[i][j] = std::min(std::min(value[i][j-1]+1, value[i-1][j]+1), value[i-1][j-1]+1);
      }
    }

  }
  /*for (int i = 0; i <= str1.length(); i++) {
    for (int j = 0; j <= str2.length(); j++) {
     std::cout << value[i][j] << " ";
    }
    std::cout << std::endl;
  }*/
  return value[str1.length()][str2.length()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
