#include <bits/stdc++.h>
using namespace std;

void f(int size, int src, int des) {
  if (size == 0)
    return ;
  int n = 6 - src - des;
  f(size - 1, src, n);
  cout << src << " " << des << '\n';
  f(size - 1, n, des);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  cout << (1 << n) - 1 << '\n';
  f(n, 1, 3);
}