#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, int size, int weights[], int values[]) {
  int w[size];
  int v[size];
  int s, tW;
  // std::cout << "size is " << size << "; capacity is " << capacity << "\n";
  while ((tW < capacity) && (s < size)) {
    double cR = 0.0;
    int cI = 0;
    for (int i = 0; i < size; i++) {
      if (weights[i] > 0) {
        if ((double(values[i]) / double(weights[i])) > cR) {
          cR = double(values[i]) / double(weights[i]);
          // std::cout << "cR set to " << cR << "\n";
          cI = i;
        }
      }
    } // get highest rate
    w[s] = weights[cI];
    v[s] = values[cI];
    tW += weights[cI];

    // std::cout << "Giving " << v[cI] << " at index " << s << " with weight " << w[cI] << "\n";
    weights[cI] = -1;
    values[cI] = -1;
    s++;
  } // sorting complete

  double value = 0.0;
  for (int i = 0; i < s; i++) {
    if (capacity <= 0) {
      return value;
    }
    if (w[i] > capacity) {
    //  std::cout << "Capacity " << capacity << " is used to add value " << double(v[i]) / double(w[i]) * capacity << "\n";
      value += double(v[i]) / double(w[i]) * capacity;
      capacity = 0;
    } else {
      value += v[i];
      capacity -= w[i];
    }
    // std::cout << "Value is now " <<  value << " with " << capacity << " capacity left \n";
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  int values[n];
  int weights[n];
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }
  double optimal_value = get_optimal_value(capacity, n, weights, values);
  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
