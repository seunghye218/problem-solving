#include <bits/stdc++.h>
using namespace std;

int N, S, cnt;
int arr[20];

void recur(int i, int sum) {
  if (i == N) {
    if (sum == S)
      ++cnt;
    return;
  }
  recur(i + 1, sum);
  recur(i + 1, sum + arr[i]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> S;
  for (int i = 0; i < N; ++i)
    cin >> arr[i];
  recur(0, 0);
  if (S == 0)
    --cnt;
  cout << cnt;
}
