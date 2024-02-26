#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // input
  int N, K;
  cin >> N >> K;
  // solving
  int bottles = 0;
  while (__builtin_popcount(N + bottles) > K) {
    ++bottles;
  }
  // output
  cout << bottles;
}