#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // input
  int N, M;
  cin >> N >> M;
  deque<int> dq;
  for (int i = 1; i <= N; ++i)
    dq.push_back(i);
  vector<int> arr(M);
  for (int i = 0; i < M; ++i)
    cin >> arr[i];
  // solve
  int cnt = 0;
  for (int &n : arr) {
    if (dq.front() != n) {
      auto dist = find(dq.begin(), dq.end(), n) - dq.begin();
      if (dist <= dq.size() / 2)
        for (; dist; --dist, ++cnt) {
          dq.push_back(dq.front());
          dq.pop_front();
        }
      else
        for (dist = dq.size() - dist; dist; --dist, ++cnt) {
          dq.push_front(dq.back());
          dq.pop_back();
        }
    }
    dq.pop_front();
  }
  cout << cnt;
}
