#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll recur(int &a, ll b, int &c) {
  if (b == 1)
    return a % c;
  ll v = recur(a, b >> 1, c);
  v = v * v % c;
  if (b & 1)
    return v * a % c;
  return v;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int A, B, C;
  cin >> A >> B >> C;
  cout << recur(A, B, C);
}