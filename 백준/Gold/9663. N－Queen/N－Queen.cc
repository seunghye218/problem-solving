#include <bits/stdc++.h>
using namespace std;

int N, cnt;
int grid[15];

void recur(int y) {
  if (y == N) {
    ++cnt;
    return;
  }
  for (int x = 0; x < N; ++x) {
    bool safe = true;
    for (int i = 0; i < y; ++i)
      if (x == grid[i] || y - i == abs(grid[i] - x))
        safe = false;
    if (safe) {
      grid[y] = x;
      recur(y + 1);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  recur(0);
  cout << cnt;
}