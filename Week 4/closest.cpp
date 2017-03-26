#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cfloat>
#include <iomanip>

using std::vector;
using std::string;
using std::pair;
using std::min;

struct Point {
    int x, y;
};

bool sortX(const Point& lx, const Point& rx) {
    if (lx.x == rx.x) {
      return (rx.y > lx.y); // sort by Y
    } else {
      return (rx.x > lx.x);
    }
}
  
bool sortY(const Point& lx, const Point& rx) {
    if (lx.y == rx.y) {
      return (rx.x > lx.x); // sort by X
    } else {
      return (rx.y > lx.y);
    }
}

double dist(const Point &a, const Point &b) {
    return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

double bruteForce(const vector<Point> points, double min = DBL_MAX) {
    for (int i = 0; i < points.size(); i++) {
        for (int j = i+1; (j < points.size()) && (abs(points[j].y - points[i].y) < min); j++) {
            min = std::min(dist(points[i], points[j]), min);
        }
    }
    return min;
}

double closestRecur(const vector<Point> points) {
    if (points.size() <= 3) 
        return bruteForce(points);

    int midIndex = points.size()/2;
    vector<Point> lP(points.begin(), points.begin()+midIndex);
    vector<Point> rP(points.begin()+midIndex, points.end());

    double delta = std::min(closestRecur(lP), closestRecur(rP));

    vector<Point> strip;
    for (int i = 0; i < points.size(); i++) {
        if (abs(points[i].x - points[midIndex].x) < delta) {
            strip.push_back(points[i]);
        }
    }

    std::sort(strip.begin(), strip.end(), sortY);

    return std::min(delta, bruteForce(strip, delta));
}

double closest_point(vector<Point> points) {
    std::sort(points.begin(), points.end(), sortX);
    return closestRecur(points);
}

int main() {
  size_t n;
  std::cin >> n;
  vector<Point> points(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> points[i].x >> points[i].y;
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << closest_point(points) << "\n";
}
