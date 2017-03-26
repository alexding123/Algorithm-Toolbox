#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  long start, end;


};

struct SegGreater {
    bool operator() (const Segment& lx, const Segment& rx) const
    {
        if (lx.start == rx.start) {
          return (rx.end > lx.end);
        } else {
          return (rx.start > lx.start);
        }
    }
};

vector<long> optimal_points(vector<Segment> &segments) {
  vector<long> points;
  std::sort(segments.begin(), segments.end(), SegGreater());
  /*for (int i = 0; i < segments.size(); i++) {
    std::cout << segments[i].start << " " << segments[i].end << "\n";
  }*/
  // sorting done

  int cI = 0;
  while (cI < segments.size()) {
    long rs = segments[cI].end;

    while ((segments[cI].start <= rs) && (cI < segments.size())) {
      if (segments[cI].end < rs) {
        rs = segments[cI].end;
      }
      cI++; 
    }
    points.push_back(rs);
  }
  return points;
}

int main() {
  long n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<long> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
