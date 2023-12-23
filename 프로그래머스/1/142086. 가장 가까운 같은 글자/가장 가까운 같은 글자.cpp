#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<int, int> m;
    for (int i = 0; i < s.size(); ++i) {
        if (m.count(s[i]))
            answer.push_back(i - m[s[i]]);
        else
            answer.push_back(-1);
        m[s[i]] = i;
    }
    return answer;
}