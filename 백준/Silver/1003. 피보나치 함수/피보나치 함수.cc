#include <bits/stdc++.h>
using namespace std;

#define ZERO first
#define ONE second

pair<int, int> fibo[41]; // cnt 0 1

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // input
  int T;
  cin >> T;
  vector<int> nums(T);
  for (int &n : nums)
    cin >> n;
  // solving
  fibo[0] = {1, 0};
  fibo[1] = {0, 1};
  int max = *max_element(nums.begin(), nums.end());
  for (int i = 2; i <= max; ++i) {
    int cnt_zero = fibo[i - 1].ZERO + fibo[i - 2].ZERO;
    int cnt_one = fibo[i - 1].ONE + fibo[i - 2].ONE;
    fibo[i] = {cnt_zero, cnt_one};
  }
  // output
  for (int &n : nums)
    cout << fibo[n].ZERO << ' ' << fibo[n].ONE << '\n';
}