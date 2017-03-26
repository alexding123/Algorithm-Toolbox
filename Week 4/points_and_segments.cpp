#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using std::vector;

struct Segment {
  long long start, end;


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


vector<int> fast_count_segments(vector<Segment> segments, vector<long long> points) {
  vector<int> cnts(points.size());
  std::sort(segments.begin(), segments.end(), SegGreater());


  for (size_t i = 0; i < points.size(); i++) {
    int cnt = 0;
    int curIndex = 0;
    while ((segments[curIndex].start <= points[i]) && (curIndex < segments.size())) { // while still possible
      if (segments[curIndex].end >= points[i]) {
        cnt++;
      }
      curIndex++;
    }
    cnts[i] = cnt;
  }


  return cnts;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<Segment> segments(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<long long> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(segments, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
