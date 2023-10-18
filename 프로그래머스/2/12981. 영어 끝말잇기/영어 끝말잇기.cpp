#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    vector<string>::iterator    pos;
    for (int i = 1; i < words.size(); ++i) {
        pos = words.begin() + i - 1; // [begin, words[i])
        if (words[i - 1].back() != words[i].front() || // 끝말이 다르거나
           find(words.begin(), pos, words[i]) != pos) { // 이미 나온적 있는 단어일 때
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            return answer;
        }
    }
    return answer;
}