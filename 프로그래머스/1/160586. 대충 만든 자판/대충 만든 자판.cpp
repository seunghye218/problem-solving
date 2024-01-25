#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> keymap1, vector<string> targets) {
    unordered_map<char, int> keymap2;
    for (string &s : keymap1)
        for (int i = 0; i < s.size(); ++i)
            if (keymap2.count(s[i]))
                keymap2[s[i]] = min(keymap2[s[i]], i + 1);
            else
                keymap2[s[i]] = i + 1;

    vector<int> answer(targets.size());
    for (int i = 0; i < targets.size(); ++i) {
        for (char &c : targets[i]) {
            if (!keymap2.count(c)) {
                answer[i] = -1;
                break;
            }
            answer[i] += keymap2[c];
        }
    }
    return answer;
}