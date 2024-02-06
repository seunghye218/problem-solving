#include <bits/stdc++.h>
using namespace std;

void recur(int &N, int &M, string s) {
  if (s.size() == M * 2 - 1) { // base case
    cout << s << "\n";
    return;
  }
  bool dup[9] = {}; // dup[i] = true if i is a duplicate
  for (int i = 0; i < s.size(); i += 2)
    dup[s[i] - '0'] = true;

  s += ' ';
  for (int i = 1; i <= N; ++i) {
    if (!dup[i])
      recur(N, M, s + to_string(i));
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  for (int i = 1; i <= N; ++i)
    recur(N, M, to_string(i));
}