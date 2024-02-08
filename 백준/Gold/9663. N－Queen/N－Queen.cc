#include <bits/stdc++.h>
using namespace std;

int N, cnt;
bool col[15], diag1[30], diag2[30];

void recur(int y) {
  for (int x = 0; x < N; ++x) {
    if (col[x] || diag1[x + y] || diag2[x - y + N - 1])
      continue;
    if (y + 1 == N) {
        ++cnt;
        continue;
    }
    col[x] = diag1[x + y] = diag2[x - y + N - 1] = true;
    recur(y + 1);
    col[x] = diag1[x + y] = diag2[x - y + N - 1] = false;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  recur(0);
  cout << cnt;
}