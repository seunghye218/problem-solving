#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int x1, x2, y1, y2, r1, r2, n;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    if (x1 == x2 && y1 == y2) {
      if (r1 == r2)
        n = -1;
      else
        n = 0;
    } else if (dist < r1 || dist < r2) {
      if (max(r1, r2) == r2)
        swap(r1, r2);
      if (r1 > r2 + dist) {
        n = 0;
      } else if (r1 == r2 + dist) {
        n = 1;
      } else {
        n = 2;
      }
    } else {
      if (dist > r1 + r2) {
        n = 0;
      } else if (dist == r1 + r2) {
        n = 1;
      } else {
        n = 2;
      }
    }
    cout << n << '\n';
  }
}