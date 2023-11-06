#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    // 옷 종류(string)에 따른 가짓수(int)
    unordered_map<string, int>  clothes_map;

    for (int i = 0; i < clothes.size(); ++i)
        ++clothes_map[clothes[i][1]];
    // mul(옷 가짓수 + 1) - 1
    for (auto it = clothes_map.begin(); it != clothes_map.end(); ++it)
        answer *= (it->second + 1);
    --answer;
    return answer;
}


