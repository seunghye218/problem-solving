#include <bits/stdc++.h>
using namespace std;

int N, S, cnt;
int arr[20];

void recur(int i, int sum, bool isEmptyOrDupSet) {
  if (!isEmptyOrDupSet && sum == S) {
    ++cnt;
    isEmptyOrDupSet = 1;
  }
  ++i;
  if (i < N) {
    recur(i, sum, isEmptyOrDupSet ? 1 : 0);
    recur(i, sum + arr[i], 0);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> S;
  for (int i = 0; i < N; ++i)
    cin >> arr[i];
  recur(-1, 0, 1);
  cout << cnt;
}
