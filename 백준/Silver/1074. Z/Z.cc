#include <bits/stdc++.h>
using namespace std;

int order, r, c;

void recur(int n, int x, int y) {
  if (n < 0)
    return;
  int mid = 1 << n, z = 0;
  if (c >= x + mid) {
    x += mid;
    ++z;
  }
  if (r >= y + mid) {
    y += mid;
    z += 2;
  }
  order += mid * mid * z;
  recur(n - 1, x, y);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N >> r >> c;
  recur(N - 1, 0, 0);
  cout << order;
}