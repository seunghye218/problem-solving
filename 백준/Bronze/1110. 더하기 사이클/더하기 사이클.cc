#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // input
  string N;
  cin >> N;
  // solving
  if (N.size() == 1)
    N = '0' + N;
  string tmp = N;
  int to_digit = 0 - '0' - '0', cnt = 0;
  do {
    if (tmp.size() == 1)
      tmp = '0' + tmp;
    tmp = ""s + tmp.back() + to_string(to_digit + tmp[0] + tmp[1]).back();
    ++cnt;
  } while (N != tmp);
  // output
  cout << cnt;
}