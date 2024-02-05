#include <bits/stdc++.h>
using namespace std;

int recur(int &a, int b, int &c) {
  if (b == 1)
    return a % c;
  long long v = recur(a, b >> 1, c);
  return ((v * v) % c * (b & 1 ? a : 1)) % c;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int A, B, C;
  cin >> A >> B >> C;
  cout << recur(A, B, C);
}