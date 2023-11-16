#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dict;
    int end_index = 1;
    for (; end_index < 27; ++end_index) // 초기화
        dict[""s + (char)('A'+end_index-1)] = end_index;
    for (auto it1 = msg.begin(); it1 != msg.end();++it1) {
        int index = dict[""s + *it1];
        string  subs = string(it1, it1+1); // 사전 키 substr
        for (auto it2 = it1+1; it2-1 != msg.end(); ++it2) {
            subs += *it2;
            if (dict.find(subs) != dict.end()) {
                ++it1;
                index = dict[subs];
            } else {
                answer.push_back(index);
                dict[subs] = end_index++;
                break;
            }
        }
    }
    return answer;
}