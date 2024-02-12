#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // input
  int N;
  cin >> N;
  set<string> words_set;
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    words_set.insert(s);
  }
  vector<string> words(words_set.begin(), words_set.end());
  // solving
  sort(words.begin(), words.end(), [](string &s1, string &s2) {
    if (s1.size() != s2.size())
      return s1.size() < s2.size();
    return s1 < s2;
  });
  for (string &s : words)
    cout << s << '\n';
}
