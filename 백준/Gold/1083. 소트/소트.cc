#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // input
  int N, S;
  cin >> N;
  vector<int> arr(N);
  for (int i = 0; i < N; ++i)
    cin >> arr[i];
  cin >> S;
  // solving
  for (int i = 0; S && i < arr.size(); ++i) {
    auto begin = arr.begin() + i;
    auto it = max_element(begin, min(arr.end(), begin + S + 1));
    for (;S && it != begin; --it, --S)
      swap(*it, *(it - 1));
  }
  // output
  for (int &n : arr)
    cout << n << ' ';
}