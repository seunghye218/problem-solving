#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 다른 글자 수 리턴.
int cnt_diff_alpha(const string &s1, const string &s2);
// begin 부터 시작함
void dfs(int i, vector<bool> visited, int target_i, const vector<vector<int>> &adjacency_list, vector<int> &results, int deep);

// begin 을 words 에 추가 후 인접 리스트 생성. 연결 기준은 한 글자 차이.
// begin 에서 이동 가능한 단어들 탐색 후 깊이 저장. 가장 작은 깊이 리턴.
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int target_i = -1;
    words.push_back(begin);
    vector<vector<int>> adjacency_list(words.size());
    vector<int>    results;

//     인접 리스트 생성
    for (int i = 0; i < words.size(); ++i) {
        if (target_i == -1 && words[i] == target)
            target_i = i;
        for (int j = i + 1; j < words.size(); ++j) {
//      한 글자 차이만 있는지 비교.
            if (cnt_diff_alpha(words[i], words[j]) == 1) {
                adjacency_list[i].push_back(j);
                adjacency_list[j].push_back(i);
            }
        }
    }
//     target이 없을 때.
    if (target_i == -1)
        return 0;
//     탐색
    dfs(words.size() - 1, vector<bool>(words.size(), false), target_i, adjacency_list, results, 0);
    vector<int>::iterator   min = min_element(results.begin(), results.end());
    return min == results.end() ? 0 : *min;
}

void dfs(int i, vector<bool> visited, int target_i, const vector<vector<int>> &adjacency_list, vector<int> &results, int deep) {
    if (i == target_i) {
        results.push_back(deep);
        return ;
    }
    visited[i] = true;
    for (int j = 0; j < adjacency_list[i].size(); ++j) {
        if (visited[adjacency_list[i][j]] == false)
            dfs(adjacency_list[i][j], visited, target_i, adjacency_list, results, deep + 1);
    }
}

int cnt_diff_alpha(const string &s1, const string &s2) {
    int diff = 0;
    for (int k = 0; k < s1.size(); ++k) {
        if (s1[k] != s2[k])
            ++diff;
        if (diff > 1)
            break;
    }
    return diff;
}