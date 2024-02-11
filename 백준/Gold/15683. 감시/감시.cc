#include <bits/stdc++.h>
using namespace std;

int N, M, cnt = 64;

struct cctv_s {
  int type, x, y;
  bool dir[4] = {}; // x y -x - y

  cctv_s(int type, int x, int y) : type(type) , x(x), y(y) {
    dir[0] = 1;
    switch (type) {
      case 2 : dir[2] = 1; break;
      case 3 : dir[3] = 1; break;
      case 4 : dir[2] = dir[3] = 1; break;
      case 5 : dir[1] = dir[2] = dir[3] = 1; break;
    }
  }

  void turn() {
    bool tmp = dir[3];
    for (int i = 3; i > 0; --i)
      dir[i] = dir[i - 1];
    dir[0] = tmp;
  }
};
  
int cnt_blind(vector<vector<int>> &room) {
  int cnt = 0;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      if (room[i][j] == 0)
        ++cnt;
  return cnt;
}

vector<vector<int>> apply_cctv(vector<vector<int>> room, vector<cctv_s> &cctvs) {
  for (auto &cctv : cctvs) {
    int x = cctv.x, y = cctv.y;
    if (cctv.dir[0])
      for (int i = x + 1; i < M && room[y][i] != 6; ++i)
        room[y][i] = '#';
    if (cctv.dir[1])
      for (int i = y + 1; i < N && room[i][x] != 6; ++i)
        room[i][x] = '#';
    if (cctv.dir[2])
      for (int i = x - 1; i >= 0 && room[y][i] != 6; --i)
        room[y][i] = '#';
    if (cctv.dir[3])
      for (int i = y - 1; i >= 0 && room[i][x] != 6; --i)
        room[i][x] = '#';
  }
  return room;
}

void recur(int d, vector<vector<int>> &room, vector<cctv_s> cctvs) {
  if (cctvs.size() == d) { // base case
    vector<vector<int>> tmp = apply_cctv(room, cctvs);
    cnt = min(cnt, cnt_blind(tmp));
    return;
  }
  recur(d + 1, room, cctvs);
  if (cctvs[d].type != 5) {
    cctvs[d].turn();
    recur(d + 1, room, cctvs);
    if (cctvs[d].type != 2) {
      cctvs[d].turn();
      recur(d + 1, room, cctvs);
      cctvs[d].turn();
      recur(d + 1, room, cctvs);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // input
  cin >> N >> M;
  vector<vector<int>> room(N, vector<int>(M));
  vector<cctv_s> cctvs;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j) {
      cin >> room[i][j];
      if (0 < room[i][j] && room[i][j] < 6)
        cctvs.push_back({room[i][j], j, i});
    }
  // solving
  recur(0, room, cctvs);
  cout << cnt;
}
