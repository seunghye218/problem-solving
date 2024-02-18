#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // input
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int M, N, K;
    cin >> M >> N >> K;
    bool field[50][50] = {};
    vector<pair<int, int>> cabbages(K);
    for (int j = 0; j < K; ++j) {
      int x, y;
      cin >> y >> x;
      cabbages[j] = {x, y};
      field[y][x] = true;
    }
    // solving
    int earthworm = 0;
    for (auto cabbage : cabbages) {
      if (field[cabbage.Y][cabbage.X]) {
        ++earthworm;
        queue<pair<int, int>> Q;
        field[cabbage.Y][cabbage.X] = false;
        Q.push({cabbage.X, cabbage.Y});
        while (!Q.empty()) {
          int x = Q.front().X, y = Q.front().Y;
          Q.pop();
          for (int d = 0; d < 4; ++d) {
            int x2 = x + dx[d], y2 = y + dy[d];
            if (x2 >= 0 && y2 >= 0 && x2 < N && y2 < M && field[y2][x2]) {
              field[y2][x2] = false;
              Q.push({x2, y2});
            }
          }
        }
      }
    }
    cout << earthworm << '\n'; // output
  }
}